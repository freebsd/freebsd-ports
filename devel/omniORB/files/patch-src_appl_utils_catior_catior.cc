--- src/appl/utils/catior/catior.cc.orig	2013-10-29 18:17:16 UTC
+++ src/appl/utils/catior/catior.cc
@@ -55,6 +55,12 @@
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
