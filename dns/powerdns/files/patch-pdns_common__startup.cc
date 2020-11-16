--- pdns/common_startup.cc.orig	2020-02-24 14:34:14 UTC
+++ pdns/common_startup.cc
@@ -191,8 +191,8 @@ void declareArguments()
 
   ::arg().setSwitch("no-shuffle","Set this to prevent random shuffling of answers - for regression testing")="off";
 
-  ::arg().set("setuid","If set, change user id to this uid for more security")="";
-  ::arg().set("setgid","If set, change group id to this gid for more security")="";
+  ::arg().set("setuid","If set, change user id to this uid for more security")="pdns";
+  ::arg().set("setgid","If set, change group id to this gid for more security")="pdns";
 
   ::arg().set("max-cache-entries", "Maximum number of entries in the query cache")="1000000";
   ::arg().set("max-packet-cache-entries", "Maximum number of entries in the packet cache")="1000000";
