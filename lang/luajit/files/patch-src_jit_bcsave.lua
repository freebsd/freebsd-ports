--- src/jit/bcsave.lua.orig	2017-05-01 18:11:00 UTC
+++ src/jit/bcsave.lua
@@ -275,7 +275,7 @@ typedef struct {
   o.sect[2].size = fofs(ofs)
   o.sect[3].type = f32(3) -- .strtab
   o.sect[3].ofs = fofs(sofs + ofs)
-  o.sect[3].size = fofs(#symname+1)
+  o.sect[3].size = fofs(#symname+2)
   ffi.copy(o.space+ofs+1, symname)
   ofs = ofs + #symname + 2
   o.sect[4].type = f32(1) -- .rodata
