--- src/hotspot/share/runtime/sharedRuntime.cpp.orig	2020-01-15 18:29:57 UTC
+++ src/hotspot/share/runtime/sharedRuntime.cpp
@@ -2806,7 +2806,7 @@ void AdapterHandlerLibrary::create_native_wrapper(cons
     if (buf != NULL) {
       CodeBuffer buffer(buf);
       double locs_buf[20];
-      buffer.insts()->initialize_shared_locs((relocInfo*)locs_buf, sizeof(locs_buf) / sizeof(relocInfo));
+      buffer.insts()->initialize_shared_locs((relocInfo*)locs_buf, (sizeof(locs_buf)) / (sizeof(relocInfo)));
       MacroAssembler _masm(&buffer);
 
       // Fill in the signature array, for the calling-convention call.
