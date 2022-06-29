--- libswirl/jit/backend/x86/rec_x86_driver.cpp.orig	2020-10-18 11:22:48 UTC
+++ libswirl/jit/backend/x86/rec_x86_driver.cpp
@@ -852,7 +852,7 @@ struct X86NGenBackend : NGenBackend
 
 						addr=retadr-5;
 
-						#if HOST_OS == OS_LINUX
+						#if HOST_OS == OS_LINUX || HOST_OS == OS_FREEBSD
 							ctx->esp += 4;
 							//restore the addr from eax to ecx so it's valid again
 							ctx->ecx = ctx->eax;
