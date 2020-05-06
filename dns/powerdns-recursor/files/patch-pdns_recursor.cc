--- pdns_recursor.cc.orig	2020-03-02 07:49:54.000000000 -0500
+++ pdns_recursor.cc	2020-03-02 07:49:54.000000000 -0500
@@ -4639,12 +4639,12 @@
 #define SYSTEMD_SETID_MSG ". When running inside systemd, use the User and Group settings in the unit-file!"
         SYSTEMD_SETID_MSG
 #endif
-        )="";
+        )="pdns";
     ::arg().set("setuid","If set, change user id to this uid for more security"
 #ifdef HAVE_SYSTEMD
         SYSTEMD_SETID_MSG
 #endif
-        )="";
+        )="pdns_recursor";
     ::arg().set("network-timeout", "Wait this number of milliseconds for network i/o")="1500";
     ::arg().set("threads", "Launch this number of threads")="2";
     ::arg().set("distributor-threads", "Launch this number of distributor threads, distributing queries to other threads")="0";
