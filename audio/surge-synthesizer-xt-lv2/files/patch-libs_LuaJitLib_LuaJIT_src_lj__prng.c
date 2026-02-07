- workaround for https://github.com/LuaJIT/LuaJIT/issues/821

--- libs/LuaJitLib/LuaJIT/src/lj_prng.c.orig	2022-03-20 05:20:02 UTC
+++ libs/LuaJitLib/LuaJIT/src/lj_prng.c
@@ -121,10 +121,10 @@ static PRGR libfunc_rgr;
 
 #if LJ_TARGET_HAS_GETENTROPY
 extern int getentropy(void *buf, size_t len);
-#ifdef __ELF__
-  __attribute__((weak))
-#endif
-;
+//#ifdef __ELF__
+//  __attribute__((weak))
+//#endif
+//;
 #endif
 
 #endif
