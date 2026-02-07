--- v8/include/v8-internal.h.orig	2025-03-24 20:50:14 UTC
+++ v8/include/v8-internal.h
@@ -232,7 +232,7 @@ using SandboxedPointer_t = Address;
 #ifdef V8_ENABLE_SANDBOX
 
 // Size of the sandbox, excluding the guard regions surrounding it.
-#if defined(V8_TARGET_OS_ANDROID)
+#if (defined(V8_TARGET_OS_ANDROID) || defined(V8_TARGET_OS_OPENBSD))
 // On Android, most 64-bit devices seem to be configured with only 39 bits of
 // virtual address space for userspace. As such, limit the sandbox to 128GB (a
 // quarter of the total available address space).
