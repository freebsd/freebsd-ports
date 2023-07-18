--- groups/bal/balst/balst_objectfileformat.h.orig	2023-08-03 22:08:19 UTC
+++ groups/bal/balst/balst_objectfileformat.h
@@ -144,7 +144,8 @@ struct ObjectFileFormat {
     struct Dummy {};
 
 #if defined(BSLS_PLATFORM_OS_SOLARIS) || \
-    defined(BSLS_PLATFORM_OS_LINUX)
+    defined(BSLS_PLATFORM_OS_LINUX) || \
+    defined(BSLS_PLATFORM_OS_FREEBSD)
 
     typedef Elf Policy;
 #   define BALST_OBJECTFILEFORMAT_RESOLVER_ELF 1
