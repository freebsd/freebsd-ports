--- include/ptlib/object.h.orig	2013-09-16 12:18:01.000000000 +0200
+++ include/ptlib/object.h	2013-09-16 12:19:59.000000000 +0200
@@ -1011,7 +1011,7 @@
                    + __GNUC_PATCHLEVEL__)
 
 // Memory pooling allocators
-#if defined(__GNUC__) && (GCC_VERSION > 40000) && !defined(P_MINGW) && !defined(P_MACOSX) 
+#if defined(__GNUC__) && (GCC_VERSION > 40000) && !defined(P_MINGW) && !defined(P_MACOSX) && !defined(_LIBCPP_VERSION)
 #include <ext/mt_allocator.h>
 template <class Type> struct PFixedPoolAllocator    : public PAllocatorTemplate<__gnu_cxx::__mt_alloc<Type>, Type> { };
 template <class Type> struct PVariablePoolAllocator : public PAllocatorTemplate<__gnu_cxx::__mt_alloc<Type>, Type> { };
