Also build when GNU keyword extensions are turned off.

This is the case when, for example, `-std=c++0x' is passed to a recent GCC or
`-std=c++11' is passed to clang.
--- libcult/cult/cli/mapper.hxx.m4~	2012-08-10 20:06:09.000000000 -0300
+++ libcult/cult/cli/mapper.hxx.m4	2012-08-10 20:06:20.000000000 -0300
@@ -35,7 +35,7 @@
   template <char const* x>
   struct Selector
   {
-    typedef typeof (Mapper::f ((Tag<x>*) (0))) Type;
+    typedef __typeof__ (Mapper::f ((Tag<x>*) (0))) Type;
   };
 `#else'
   template <char const* x>
