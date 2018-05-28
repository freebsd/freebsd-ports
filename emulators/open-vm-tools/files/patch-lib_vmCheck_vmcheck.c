--- lib/vmCheck/vmcheck.c.orig	2018-03-30 18:44:35 UTC
+++ lib/vmCheck/vmcheck.c
@@ -135,6 +135,7 @@ VmCheckSafe(SafeCheckFn checkFn)
 #else
    do {
       int signals[] = {
+         SIGBUS,
          SIGILL,
          SIGSEGV,
       };
