--- lib/vmCheck/vmcheck.c.orig	2018-07-13 18:54:23 UTC
+++ lib/vmCheck/vmcheck.c
@@ -153,6 +153,7 @@ VmCheckSafe(SafeCheckFn checkFn)
 #else
    do {
       int signals[] = {
+         SIGBUS,
          SIGILL,
          SIGSEGV,
       };
