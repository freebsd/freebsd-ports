--- dns_balance.rb.orig	2005-06-10 22:23:56 UTC
+++ dns_balance.rb
@@ -7,14 +7,7 @@
 # $Id: dns_balance.rb,v 1.25 2003/06/13 22:07:27 elca Exp $
 
 # DNS Balance の存在するパス名
-if ENV["ROOT"] == nil
-  warn("\"ROOT\" environment is recommended. Use current directory in this time.")
-  PREFIX = "."
-#  exit(111)
-else
-  PREFIX = ENV["ROOT"]
-  $LOAD_PATH.unshift(PREFIX)
-end
+$LOAD_PATH.unshift("%%PREFIX%%/etc/%%PORTNAME%%", "%%PREFIX%%/lib/%%PORTNAME%%")
 $LOAD_PATH.freeze
 
 require 'socket'
@@ -204,6 +197,14 @@ OptionParser::new {
   opt.on("--as", "Enable AS namespace") {
     OPT["as"] = true
   }
+  opt.on("-l LOGFILE", String, "Print log to LOGFILE") {
+    |o|
+    OPT["l"] = o;
+  }
+  opt.on("-p PIDFILE", String, "Record PID to PIDFILE") {
+    |o|
+    OPT["p"] = o;
+  }
   opt.on_tail("-h", "--help", "Show this help message and exit") {
     STDERR.printf("%s", opt.to_s)
     exit(111)
@@ -212,10 +213,42 @@ OptionParser::new {
 }
 OPT.freeze
 
-ML = MultiLog::new
-ML.open
+exit! if fork
+Process::setsid
+exit! if fork
+STDIN.close
+STDOUT.close
+STDERR.close
+
+$pidfile = nil
+if OPT["p"]
+  $pidfile = OPT["p"]
+  File::open($pidfile, 'w') { |f| f.puts $$ }
+end
+
+$logout = nil                                                               
+if OPT["l"]
+  $logout = File::open(OPT["l"], 'a+')
+  $logout.sync = true
+end
+
+[0, 2, 3, 5, 10, 13, 15].each do |sig|
+  trap(sig) {
+    File::unlink($pidfile) if $pidfile
+    $logout.close if $logout
+    exit
+  }
+end
+
+ ML = MultiLog.new
+if OPT["l"] 
+  $logout = File::open(OPT["l"], 'a+')
+  $logout.sync = true
+  ML.open($logout)
+else
+  ML.open
+end
 
-ML.log("dir: " + PREFIX)
 ML.log("start")
 
 
@@ -224,7 +257,7 @@ ML.log("start")
 #
 Thread::start {
   loop {
-    if test(?r, PREFIX + "/addr") || test(?r, "./addr")
+    if test(?r, "%%ETCDIR%%" + "/addr")
       begin
 	load("addr")
 
@@ -234,7 +267,7 @@ Thread::start {
       end
     end
 
-    #if test(?r, PREFIX + "/addr-once") || test(?r, "./addr-once")
+    #if test(?r, "%%ETCDIR%%" + "/addr-once")
     #  Thread.exit
     #end
 
