--- src/mapi/entry_x86-64_tls.h.orig	2013-10-05 05:59:22.000000000 +0200
+++ src/mapi/entry_x86-64_tls.h	2014-07-29 20:28:05.000000000 +0200
@@ -63,8 +63,8 @@ entry_patch_public(void)
 {
 }
 
-static char
-x86_64_entry_start[];
+extern char
+x86_64_entry_start[] __attribute__((visibility("hidden")));
 
 mapi_func
 entry_get_public(int slot)
