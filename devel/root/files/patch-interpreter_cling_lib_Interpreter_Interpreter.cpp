--- interpreter/cling/lib/Interpreter/Interpreter.cpp.orig	2024-05-30 18:23:48 UTC
+++ interpreter/cling/lib/Interpreter/Interpreter.cpp
@@ -465,8 +465,17 @@ namespace cling {
     const char* Attr = LangOpts.CPlusPlus ? " throw () " : "";
 #else
     const char* LinkageCxx = Linkage;
+#ifdef __FreeBSD__
+// atexit-like commands need 'throw()' specifier on FreeBSD 15
+#if __FreeBSD_cc_version >= 1500000
+    const char* Attr = " throw () ";
+#else
     const char* Attr = "";
 #endif
+#else
+    const char* Attr = "";
+#endif // __FreeBSD__
+#endif // __GLIBC__
 
 #if defined(__GLIBCXX__)
     const char* cxa_atexit_is_noexcept = LangOpts.CPlusPlus ? " noexcept" : "";
