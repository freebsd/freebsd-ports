--- runtime/druntime/src/rt/sections_elf_shared.d.orig	2022-11-21 16:37:34 UTC
+++ runtime/druntime/src/rt/sections_elf_shared.d
@@ -1150,17 +1150,6 @@ else
 
 version (LDC)
 {
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
-    else
         extern(C) void* __tls_get_addr(tls_index* ti) nothrow @nogc;
 }
 else
