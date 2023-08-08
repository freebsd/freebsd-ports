--- rec-main.cc.orig	2023-06-30 06:58:36 UTC
+++ rec-main.cc
@@ -2829,13 +2829,13 @@ static void initArgs()
               SYSTEMD_SETID_MSG
 #endif
               )
-    = "";
+    = "pdns";
   ::arg().set("setuid", "If set, change user id to this uid for more security"
 #ifdef HAVE_SYSTEMD
               SYSTEMD_SETID_MSG
 #endif
               )
-    = "";
+    = "pdns_recursor";
   ::arg().set("network-timeout", "Wait this number of milliseconds for network i/o") = "1500";
   ::arg().set("threads", "Launch this number of threads") = "2";
   ::arg().set("distributor-threads", "Launch this number of distributor threads, distributing queries to other threads") = "0";
