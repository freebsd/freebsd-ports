--- common/ac/time.h.orig	2007-09-30 13:52:44 UTC
+++ common/ac/time.h
@@ -27,7 +27,7 @@
  * Catch-22: Dec Alpha OSF/1: need to include time.h before sys/time.h
  * before time.h
  */
-#ifdef __alpha__
+#ifdef __osf1__
 #ifndef _CLOCK_ID_T
 #define _CLOCK_ID_T
 typedef int clockid_t;
