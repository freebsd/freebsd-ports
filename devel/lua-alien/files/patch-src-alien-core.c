--- src/alien/core.c~
+++ src/alien/core.c
@@ -301,7 +301,7 @@ static void *alien_loadfunc (lua_State *
 #define FFI_STDCALL FFI_DEFAULT_ABI
 #endif
 
-#ifdef DARWIN
+#if defined(DARWIN) || !defined(FFI_SYSV)
 #define FFI_SYSV FFI_DEFAULT_ABI
 #endif
 
