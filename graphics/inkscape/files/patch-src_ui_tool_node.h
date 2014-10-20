--- src/ui/tool/node.h.orig	2014-10-20 01:38:50.972399465 +0200
+++ src/ui/tool/node.h	2014-10-20 01:37:10.561420788 +0200
@@ -38,7 +38,7 @@
 }
 }
 
-#if __cplusplus < 201103L
+#if __cplusplus < 201103L && !defined(_LIBCPP_VERSION)
 namespace std {
 namespace tr1 {
 template <typename N> struct hash< Inkscape::UI::NodeIterator<N> >;
