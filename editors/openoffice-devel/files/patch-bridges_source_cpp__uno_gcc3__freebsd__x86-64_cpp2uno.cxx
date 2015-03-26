--- bridges/source/cpp_uno/gcc3_freebsd_x86-64/cpp2uno.cxx.orig	2014-09-19 17:51:12 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_x86-64/cpp2uno.cxx
@@ -24,9 +24,10 @@
 // MARKER(update_precomp.py): autogen include statement, do not remove
 #include "precompiled_bridges.hxx"
 
-#include <stdio.h>
-#include <stdlib.h>
-#include <hash_map>
+#include <typeinfo>
+#include <exception>
+#include <cstddef>
+#include <cxxabi.h>
 
 #include <rtl/alloc.h>
 #include <osl/mutex.hxx>
