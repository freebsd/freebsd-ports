--- mono/mini/mini-x86.c.orig	Thu Nov  2 15:09:51 2006
+++ mono/mini/mini-x86.c	Sun Dec 17 19:51:08 2006
@@ -113,7 +113,7 @@
 
 static X86_Reg_No param_regs [] = { 0 };
 
-#ifdef PLATFORM_WIN32
+#if defined(PLATFORM_WIN32) || defined(PLATFORM_BSD)
 static X86_Reg_No return_regs [] = { X86_EAX, X86_EDX };
 #endif
 
@@ -179,7 +179,7 @@
 	else 
 		size = mono_type_stack_size (&klass->byval_arg, NULL);
 
-#ifdef PLATFORM_WIN32
+#if defined(PLATFORM_WIN32) || defined(PLATFORM_BSD)
 	if (sig->pinvoke && is_return) {
 		MonoMarshalType *info;
 
