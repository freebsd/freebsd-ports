--- src/appl/utils/convertior/convertior.cc.orig	2020-09-21 21:47:46 UTC
+++ src/appl/utils/convertior/convertior.cc
@@ -38,6 +38,12 @@ using namespace std;
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
