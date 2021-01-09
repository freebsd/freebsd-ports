--- source/views/view_hexeditor.cpp.orig	2021-01-08 19:12:16 UTC
+++ source/views/view_hexeditor.cpp
@@ -13,6 +13,10 @@
 #undef __STRICT_ANSI__
 #include <cstdio>
 
+#if defined(__FreeBSD__)
+    #define ftello64 ftell
+#endif
+
 namespace hex {
 
     ViewHexEditor::ViewHexEditor(std::vector<lang::PatternData*> &patternData)
