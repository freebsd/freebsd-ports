LLVM doesn't handle RTTI in the same way as an LSB implementation, but
LibreOffice expects to use it in that way.  Define a couple of necessary
functions locally to allow that to happen.

--- bridges/source/cpp_uno/gcc3_linux_intel/share.hxx.orig	2019-02-13 06:11:36.000000000 +0800
+++ bridges/source/cpp_uno/gcc3_linux_intel/share.hxx	2019-03-01 23:28:17.003752000 +0800
@@ -33,6 +33,33 @@
 #include <uno/any2.h>
 #include <uno/mapping.h>
 
+#if !HAVE_CXXABI_H_CLASS_TYPE_INFO
+// <https://mentorembedded.github.io/cxx-abi/abi.html>,
+// libstdc++-v3/libsupc++/cxxabi.h:
+namespace __cxxabiv1 {
+class __class_type_info: public std::type_info {
+public:
+    explicit __class_type_info(char const * n): type_info(n) {}
+    ~__class_type_info() override;
+};
+}
+#endif
+
+#if !HAVE_CXXABI_H_SI_CLASS_TYPE_INFO
+// <https://mentorembedded.github.io/cxx-abi/abi.html>,
+// libstdc++-v3/libsupc++/cxxabi.h:
+namespace __cxxabiv1 {
+class __si_class_type_info: public __class_type_info {
+public:
+    __class_type_info const * __base_type;
+    explicit __si_class_type_info(
+        char const * n, __class_type_info const *base):
+        __class_type_info(n), __base_type(base) {}
+    ~__si_class_type_info() override;
+};
+}
+#endif
+
 namespace CPPU_CURRENT_NAMESPACE
 {
 
