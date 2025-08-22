--- pdns/auth-main.cc.orig	2025-08-22 07:51:37 UTC
+++ pdns/auth-main.cc
@@ -282,8 +282,8 @@ static void declareArguments()
 
   ::arg().setSwitch("no-shuffle", "Set this to prevent random shuffling of answers - for regression testing") = "off";
 
-  ::arg().set("setuid", "If set, change user id to this uid for more security") = "";
-  ::arg().set("setgid", "If set, change group id to this gid for more security") = "";
+  ::arg().set("setuid", "If set, change user id to this uid for more security") = "pdns";
+  ::arg().set("setgid", "If set, change group id to this gid for more security") = "pdns";
 
   ::arg().set("max-cache-entries", "Maximum number of entries in the query cache") = "1000000";
   ::arg().set("max-packet-cache-entries", "Maximum number of entries in the packet cache") = "1000000";
