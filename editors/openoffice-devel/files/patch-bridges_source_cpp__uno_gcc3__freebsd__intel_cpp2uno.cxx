--- bridges/source/cpp_uno/gcc3_freebsd_intel/cpp2uno.cxx.orig	2014-09-19 17:51:13 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/cpp2uno.cxx
@@ -24,6 +24,11 @@
 // MARKER(update_precomp.py): autogen include statement, do not remove
 #include "precompiled_bridges.hxx"
 
+#include <typeinfo>
+#include <exception>
+#include <cstddef>
+#include <cxxabi.h>
+
 #include <com/sun/star/uno/genfunc.hxx>
 #include "com/sun/star/uno/RuntimeException.hpp"
 #include <uno/data.h>
