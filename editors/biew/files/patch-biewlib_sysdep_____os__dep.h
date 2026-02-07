--- biewlib/sysdep/__os_dep.h.orig	2009-10-16 13:50:47 UTC
+++ biewlib/sysdep/__os_dep.h
@@ -364,11 +364,7 @@ extern void      __FASTCALL__ __OsRestoreTimer(void);
 #define FILESIZE_MAX ULONG_MAX
 #endif
 
-#if __WORDSIZE >= 64
-typedef void* bhandle_t;
-#else
 typedef int   bhandle_t;
-#endif
 #define NULL_HANDLE ((bhandle_t)-1)
 
                    /** Closes opened stream
