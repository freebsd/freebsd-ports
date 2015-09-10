--- plugins/scintilla/scintilla/src/SplitVector.h.orig	2015-06-10 20:14:00.051095000 -0400
+++ plugins/scintilla/scintilla/src/SplitVector.h	2015-06-10 20:20:33.371490000 -0400
@@ -9,6 +9,8 @@
 #ifndef SPLITVECTOR_H
 #define SPLITVECTOR_H
 
+#include <algorithm>
+
 template <typename T>
 class SplitVector {
 protected:
