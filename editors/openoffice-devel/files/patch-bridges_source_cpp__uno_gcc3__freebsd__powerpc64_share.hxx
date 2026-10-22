--- bridges/source/cpp_uno/gcc3_freebsd_powerpc64/share.hxx.orig	2026-09-18 00:49:04 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_powerpc64/share.hxx
@@ -145,4 +145,6 @@ namespace ppc64
 {
      enum ppclimits { MAX_GPR_REGS = 8, MAX_SSE_REGS = 13 };
     bool return_in_hidden_param( typelib_TypeDescriptionReference *pTypeRef );
+    sal_Int32 return_in_fprs( typelib_TypeDescriptionReference *pTypeRef, typelib_TypeClass & eBase );
+    const typelib_TypeClass TYPECLASS_FPRS = (typelib_TypeClass) 100;
 }
