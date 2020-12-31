--- lib/vmCheck/vmcheck.c.orig	2020-10-16 23:15:58 UTC
+++ lib/vmCheck/vmcheck.c
@@ -144,6 +144,7 @@ VmCheckSafe(SafeCheckFn checkFn)
 #else
    do {
       int signals[] = {
+         SIGBUS,
          SIGILL,
          SIGSEGV,
       };
