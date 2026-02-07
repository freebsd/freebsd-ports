--- src/appl/utils/catior/catior.cc.orig	2021-04-11 12:58:05 UTC
+++ src/appl/utils/catior/catior.cc
@@ -48,6 +48,12 @@ using namespace std;
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
