--- lib/vmCheck/vmcheck.c.orig	2017-02-24 22:15:37 UTC
+++ lib/vmCheck/vmcheck.c
@@ -134,6 +134,7 @@ VmCheckSafe(SafeCheckFn checkFn)
 #else
    do {
       int signals[] = {
+         SIGBUS,
          SIGILL,
          SIGSEGV,
       };
