--- boost/spirit/impl/primitives.ipp.orig	Thu Nov 15 12:57:25 2001
+++ boost/spirit/impl/primitives.ipp	Wed Aug 20 13:22:25 2003
@@ -284,7 +284,8 @@
 //
 //  On some systems the is* functions are defined as macros
 
-#if defined(_MSC_VER) || _STLPORT_VERSION >= 0x450 
+#if defined(_MSC_VER) || _STLPORT_VERSION >= 0x450 || \
+    (defined(__GNUC__) && __GNUC__ >= 3)
 // is* functions already setup
 #else
 #ifndef isalnum
