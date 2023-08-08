--- v8/include/v8-internal.h.orig	2023-05-25 00:46:26 UTC
+++ v8/include/v8-internal.h
@@ -173,7 +173,7 @@ using SandboxedPointer_t = Address;
 #ifdef V8_ENABLE_SANDBOX
 
 // Size of the sandbox, excluding the guard regions surrounding it.
-#ifdef V8_TARGET_OS_ANDROID
+#if defined(V8_TARGET_OS_ANDROID) || defined(V8_TARGET_OS_OPENBSD)
 // On Android, most 64-bit devices seem to be configured with only 39 bits of
 // virtual address space for userspace. As such, limit the sandbox to 128GB (a
 // quarter of the total available address space).
