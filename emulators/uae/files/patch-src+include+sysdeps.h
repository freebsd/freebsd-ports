--- src/include/sysdeps.h.orig	Mon Nov 19 23:58:46 2001
+++ src/include/sysdeps.h	Thu Sep 30 16:59:24 2004
@@ -103,12 +103,12 @@
 };
 #endif
 
-#if defined(__GNUC__) && defined(AMIGA)
-/* gcc on the amiga need that __attribute((regparm)) must */
-/* be defined in function prototypes as well as in        */
-/* function definitions !                                 */
+#if defined(__GNUC__)
+/* recent gcc needs that __attribute((regparm)) must */
+/* be defined in function prototypes as well as in   */
+/* function definitions !                            */
 #define REGPARAM2 REGPARAM
-#else /* not(GCC & AMIGA) */
+#else /* not GCC */
 #define REGPARAM2
 #endif
 
