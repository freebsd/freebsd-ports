--- src/mapi/entry_x86_tls.h.orig	2013-10-05 05:59:22.000000000 +0200
+++ src/mapi/entry_x86_tls.h	2014-07-29 20:28:05.000000000 +0200
@@ -73,8 +73,8 @@ __asm__(".text");
 extern unsigned long
 x86_current_tls();
 
-static char x86_entry_start[];
-static char x86_entry_end[];
+extern char x86_entry_start[] __attribute__((visibility("hidden")));
+extern char x86_entry_end[] __attribute__((visibility("hidden")));
 
 void
 entry_patch_public(void)
