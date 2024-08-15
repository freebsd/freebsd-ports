--- runtime/druntime/src/rt/sections_elf_shared.d.orig	2024-07-04 10:32:30 UTC
+++ runtime/druntime/src/rt/sections_elf_shared.d
@@ -1174,17 +1174,7 @@ version (LDC)
 {
     version (Android) version (X86) version = Android_X86;
 
-    version (PPC)
-    {
-        extern(C) void* __tls_get_addr_opt(tls_index* ti) nothrow @nogc;
-        alias __tls_get_addr = __tls_get_addr_opt;
-    }
-    else version (PPC64)
-    {
-        extern(C) void* __tls_get_addr_opt(tls_index* ti) nothrow @nogc;
-        alias __tls_get_addr = __tls_get_addr_opt;
-    }
-    else version (Android_X86) // extra underscore
+    version (Android_X86) // extra underscore
     {
         extern(C) void* ___tls_get_addr(tls_index* ti) nothrow @nogc;
         alias __tls_get_addr = ___tls_get_addr;
