--- pdns_recursor.cc.orig	Wed Jan 17 23:45:51 2007
+++ pdns_recursor.cc	Thu Jan 18 00:01:47 2007
@@ -1669,8 +1669,8 @@
     ::arg().set("daemon","Operate as a daemon")="yes";
     ::arg().set("log-common-errors","If we should log rather common errors")="yes";
     ::arg().set("chroot","switch to chroot jail")="";
-    ::arg().set("setgid","If set, change group id to this gid for more security")="";
-    ::arg().set("setuid","If set, change user id to this uid for more security")="";
+    ::arg().set("setgid","If set, change group id to this gid for more security")="pdns";
+    ::arg().set("setuid","If set, change user id to this uid for more security")="pdns_recursor";
 #ifdef WIN32
     ::arg().set("quiet","Suppress logging of questions and answers")="off";
     ::arg().setSwitch( "register-service", "Register the service" )= "no";
@@ -1691,7 +1691,7 @@
     ::arg().set("client-tcp-timeout","Timeout in seconds when talking to TCP clients")="2";
     ::arg().set("max-tcp-clients","Maximum number of simultaneous TCP clients")="128";
     ::arg().set("hint-file", "If set, load root hints from this file")="";
-    ::arg().set("max-cache-entries", "If set, maximum number of entries in the main cache")="0";
+    ::arg().set("max-cache-entries", "If set, maximum number of entries in the main cache")="500000";
     ::arg().set("max-negative-ttl", "maximum number of seconds to keep a negative cached entry in memory")="3600";
     ::arg().set("server-id", "Returned when queried for 'server.id' TXT, defaults to hostname")="";
     ::arg().set("remotes-ringbuffer-entries", "maximum number of packets to store statistics for")="0";
