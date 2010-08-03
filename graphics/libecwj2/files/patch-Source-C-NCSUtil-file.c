--- Source/C/NCSUtil/file.c.orig	2006-07-03 05:15:02.000000000 +0400
+++ Source/C/NCSUtil/file.c	2010-07-29 16:40:02.000000000 +0400
@@ -203,8 +203,10 @@
 	return (INT64) lseek64(hFile, (off64_t)nOffset, origin);
 #elif defined IRIX
 	return (INT64) lseek64(hFile, (off64_t)nOffset, origin);
-#elif defined MACOSX
-    return (INT64) lseek(hFile, nOffset, origin);
+#elif defined MACOSX || defined FREEBSD
+	return (INT64) lseek(hFile, nOffset, origin);
+#else
+#error NCSFileSeekNative() routine is not defined for this platform
 #endif
 }
 
@@ -253,6 +255,8 @@
 	return (INT64) lseek64(hFile, (off64_t)0, SEEK_CUR);
 #elif defined MACOSX
 	return (INT64) lseek(hFile, (long)0, SEEK_CUR);
+#elif defined FREEBSD
+	return (INT64) lseek(hFile, (off_t)0, SEEK_CUR);
 #else
 #error ERROR: EcwFileGetPos() routine is not defined for this platform
 #endif
