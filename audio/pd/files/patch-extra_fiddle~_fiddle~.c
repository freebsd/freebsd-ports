--- extra/fiddle~/fiddle~.c.orig	Mon Apr 15 15:52:45 2002
+++ extra/fiddle~/fiddle~.c	Fri May 24 23:12:27 2002
@@ -40,9 +40,7 @@ This file is downloadable from http://ww
 #define fexp exp
 #define fsqrt sqrt
 #pragma warning (disable: 4305 4244)
-#endif
-
-#if (defined(__linux__) || defined(MACOSX))
+#else
 #define flog log
 #define fexp exp
 #define fsqrt sqrt
