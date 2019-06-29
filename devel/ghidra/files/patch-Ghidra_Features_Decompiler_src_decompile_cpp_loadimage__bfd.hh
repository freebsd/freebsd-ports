--- Ghidra/Features/Decompiler/src/decompile/cpp/loadimage_bfd.hh.orig	2019-04-03 17:38:23 UTC
+++ Ghidra/Features/Decompiler/src/decompile/cpp/loadimage_bfd.hh
@@ -21,6 +21,9 @@
 #define __LOADIMAGE_BFD__
 
 #include "loadimage.hh"
+
+#define PACKAGE
+#define PACKAGE_VERSION
 #include <bfd.h>
 
 struct ImportRecord {
