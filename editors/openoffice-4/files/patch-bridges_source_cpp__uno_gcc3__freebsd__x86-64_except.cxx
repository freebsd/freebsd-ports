--- bridges/source/cpp_uno/gcc3_freebsd_x86-64/except.cxx.orig	2014-09-19 17:51:13 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_x86-64/except.cxx
@@ -24,7 +24,7 @@
 // MARKER(update_precomp.py): autogen include statement, do not remove
 #include "precompiled_bridges.hxx"
 
-#if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 6))
+#if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 6)) || defined(__clang__)
 #include <exception>
 #endif
 
