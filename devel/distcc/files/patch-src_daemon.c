--- src/daemon.c.orig	2024-09-20 02:11:57 UTC
+++ src/daemon.c
@@ -160,7 +160,7 @@ static void dcc_warn_masquerade_whitelist(void) {
                        " --enable-tcp-insecure. To set up masquerade automatically" \
                        " run update-distcc-symlinks.";
 
-    e = opendir("/usr/lib/distcc");
+    e = opendir("/usr/local/libexec/distcc");
     d = opendir(LIBDIR "/distcc");
     if (!e && !d) {
         rs_log_crit(LIBDIR "/distcc not found. %s", warn);
