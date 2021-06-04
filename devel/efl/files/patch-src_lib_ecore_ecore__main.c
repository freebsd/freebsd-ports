--- src/lib/ecore/ecore_main.c.orig	2020-10-08 08:41:34 UTC
+++ src/lib/ecore/ecore_main.c
@@ -4,6 +4,8 @@
 
 #define EINA_SLSTR_INTERNAL
 
+#define FD_SETSIZE 8192
+
 #ifdef _WIN32
 # ifndef USER_TIMER_MINIMUM
 #  define USER_TIMER_MINIMUM 0x0a
