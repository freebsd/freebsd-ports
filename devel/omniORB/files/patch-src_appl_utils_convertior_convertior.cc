--- src/appl/utils/convertior/convertior.cc.orig	2017-02-20 22:45:59 UTC
+++ src/appl/utils/convertior/convertior.cc
@@ -42,6 +42,12 @@
 // macro called minor.
 #undef minor
 
+#ifdef minor
+  // Digital Unix 3.2, and may be others as well, defines minor() as
+  // a macro in its sys/types.h. Get rid of it!
+#undef minor
+#endif
+
 #ifndef Swap16
 #define Swap16(s) ((((s) & 0xff) << 8) | (((s) >> 8) & 0xff))
 #else
