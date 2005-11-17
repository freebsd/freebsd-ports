diff -ruN ./code/unix/linux_common.c ../quake3-1.32b-BUILT/./code/unix/linux_common.c
--- ./code/unix/linux_common.c	Tue Aug 16 02:10:07 2005
+++ ../quake3-1.32b-BUILT/./code/unix/linux_common.c	Tue Aug 23 13:38:35 2005
@@ -33,6 +33,7 @@
 #include <unistd.h>   // AH - for size_t
 #include <string.h>
 
+
 // bk001207 - we need something under Linux, too. Mac?
 #if 1 // defined(C_ONLY) // bk010102 - dedicated?
 void Com_Memcpy (void* dest, const void* src, const size_t count) {
@@ -340,5 +341,6 @@
 		break;
 	}
 }
+
 
 #endif
