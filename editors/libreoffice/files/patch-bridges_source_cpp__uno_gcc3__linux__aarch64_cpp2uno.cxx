--- bridges/source/cpp_uno/gcc3_linux_aarch64/cpp2uno.cxx.orig	2020-03-11 17:18:35 UTC
+++ bridges/source/cpp_uno/gcc3_linux_aarch64/cpp2uno.cxx
@@ -321,9 +321,16 @@ extern "C" void vtableSlotCall(
     double fpr2, double fpr3, double fpr4, double fpr5, double fpr6,
     double fpr7, ...)
 {
-    register void * volatile indirectRet asm ("x8");
-    register sal_Int32 volatile functionIndex asm ("x9");
-    register sal_Int32 volatile vtableOffset asm ("x10");
+    void * volatile indirectRet;
+    sal_Int32 volatile functionIndex, vtableOffset;
+
+    asm volatile(
+        "mov %0, x8\n"
+        "mov %1, x9\n"
+        "mov %2, x10\n"
+        : "=r" (indirectRet), "=r" (functionIndex), "=r" (vtableOffset)
+        ::);
+
     va_list ap;
     va_start(ap, fpr7);
     assert(sizeof (va_list) == sizeof (aarch64_va_list));
