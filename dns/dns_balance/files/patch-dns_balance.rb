--- dns_balance.rb.orig	Thu Feb  6 17:39:46 2003
+++ dns_balance.rb	Sun Jul 18 00:58:12 2004
@@ -19,6 +19,8 @@
 require 'thread'
 require 'getopts'
 
+$:.unshift "%%PREFIX%%/etc/dns_balance", "%%PREFIX%%/lib/dns_balance"
+
 require 'datatype.rb'
 require 'multilog.rb'
 require 'log_writer.rb'
@@ -39,9 +41,11 @@
 # ´Ø¿ô
 
 def usage()
-  print "Usage: ruby dns_balance.rb [-lh] [-i ipaddr]\n"
+  print "Usage: dns_balance.rb [-h] [-i ipaddr] [-l logfile] [-p pidfile]\n"
+  print "       -l logfile print log to logfile\n"
   print "       -i ipaddr  listen IP address (default:0.0.0.0)\n"
   print "       -h         help message\n"
+  print "       -p pidfile record PID in pidfile\n"
   print "       --as       Enable AS namespace\n"
   exit(111)
 end
@@ -184,12 +188,45 @@
 # main
 
 srand()
-getopts("lh", "i:0.0.0.0", "d:", "as")
+getopts("h", "i:0.0.0.0", "d:", "as", 'l:', 'p:')
 
 usage() if $OPT_h
 
+exit! if fork
+Process::setsid
+exit! if fork
+STDIN.close
+STDOUT.close
+STDERR.close
+
+$pidfile = nil
+if $OPT_p
+  $pidfile = $OPT_p
+  File::open($pidfile, 'w') { |f| f.puts $$ }
+end
+
+$logout = nil
+if $OPT_l
+  $logout = File::open($OPT_l, 'a+')
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
 ML = MultiLog.new
-ML.open
+if $OPT_l
+  $logout = File::open($OPT_l, 'a+')
+  $logout.sync = true
+  ML.open($logout)
+else
+  ML.open
+end
 
 ML.log("dir: " + Prefix)
 ML.log("start")
