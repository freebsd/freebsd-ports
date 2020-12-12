--- source/views/view_hexeditor.cpp.orig	2020-12-06 20:40:57 UTC
+++ source/views/view_hexeditor.cpp
@@ -13,6 +13,10 @@
 #undef __STRICT_ANSI__
 #include <cstdio>
 
+#if defined(__APPLE__) || defined(__FreeBSD__)
+    #define ftello64 ftell
+#endif
+
 namespace hex {
 
     ViewHexEditor::ViewHexEditor(prv::Provider* &dataProvider, std::vector<lang::PatternData*> &patternData)
