--- src/mapi/entry_x86_tsd.h.orig	2013-10-05 05:59:22.000000000 +0200
+++ src/mapi/entry_x86_tsd.h	2014-07-29 20:28:05.000000000 +0200
@@ -60,8 +60,8 @@ __asm__(".balign 32\n"
 #include <string.h>
 #include "u_execmem.h"
 
-static const char x86_entry_start[];
-static const char x86_entry_end[];
+extern const char x86_entry_start[] __attribute__((visibility("hidden")));
+extern const char x86_entry_end[] __attribute__((visibility("hidden")));
 
 void
 entry_patch_public(void)
