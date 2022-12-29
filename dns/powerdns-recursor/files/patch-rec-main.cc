--- rec-main.cc.orig	2022-12-09 10:46:42 UTC
+++ rec-main.cc
@@ -2609,13 +2609,13 @@ int main(int argc, char** argv)
                 SYSTEMD_SETID_MSG
 #endif
                 )
-      = "";
+      = "pdns";
     ::arg().set("setuid", "If set, change user id to this uid for more security"
 #ifdef HAVE_SYSTEMD
                 SYSTEMD_SETID_MSG
 #endif
                 )
-      = "";
+      = "pdns_recursor";
     ::arg().set("network-timeout", "Wait this number of milliseconds for network i/o") = "1500";
     ::arg().set("threads", "Launch this number of threads") = "2";
     ::arg().set("distributor-threads", "Launch this number of distributor threads, distributing queries to other threads") = "0";
