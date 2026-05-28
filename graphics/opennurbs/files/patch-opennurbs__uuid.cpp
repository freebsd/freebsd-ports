--- opennurbs_uuid.cpp.orig	2026-04-14 14:48:14 UTC
+++ opennurbs_uuid.cpp
@@ -221,7 +221,7 @@ bool ON_CreateUuid( ON_UUID& new_uuid )
   return true;
 #else
 
-#if defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM)
+#if defined(ON_RUNTIME_LINUX) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__)
   uuid_generate((unsigned char*)&new_uuid);
   return true;
 #else
