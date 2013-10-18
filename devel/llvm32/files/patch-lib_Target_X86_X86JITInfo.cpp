$NetBSD: patch-lib_Target_X86_X86JITInfo.cpp,v 1.1 2013/04/02 12:00:05 joerg Exp $
$FreeBSD$

It is not yet decided whether extern "C" applies to static functions, so
be explicit for now.

--- lib/Target/X86/X86JITInfo.cpp.orig	2013-04-01 12:16:22.000000000 +0000
+++ lib/Target/X86/X86JITInfo.cpp
@@ -342,6 +342,17 @@ extern "C" {
 /// must locate the start of the stub or call site and pass it into the JIT
 /// compiler function.
 extern "C" {
+
+#if !(defined (X86_64_JIT) && defined(_MSC_VER))
+ // the following function is called only from this translation unit,
+ // unless we are under 64bit Windows with MSC, where there is
+ // no support for inline assembly
+static
+#endif
+void LLVM_ATTRIBUTE_USED
+X86CompilationCallback2(intptr_t *StackPtr, intptr_t RetAddr)
+__asm__("X86CompilationCallback2");
+
 #if !(defined (X86_64_JIT) && defined(_MSC_VER))
  // the following function is called only from this translation unit,
  // unless we are under 64bit Windows with MSC, where there is
