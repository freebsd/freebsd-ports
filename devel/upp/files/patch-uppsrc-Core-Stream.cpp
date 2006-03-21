--- uppsrc/Core/Stream.cpp.orig	Sat Mar  4 17:09:13 2006
+++ uppsrc/Core/Stream.cpp	Sat Mar  4 17:09:22 2006
@@ -10,11 +10,14 @@
 #define LLOGHEXDUMP(x, y) // RLOGHEXDUMP(x, y)
 
 #ifdef PLATFORM_POSIX
+#define LOFF_T_      off_t
 #define LSEEK64_     lseek
 #define FTRUNCATE64_ ftruncate
 #endif
 
 #ifdef PLATFORM_LINUX
+#undef  LOFF_T_
+#define LOFF_T_      loff_t
 #undef  LSEEK64_
 #define LSEEK64_     lseek64
 #undef  FTRUNCATE64_
@@ -1217,12 +1220,12 @@
 void FileStream::SetStreamSize(int64 pos)
 {
 	if(handle < 0) return;
-	loff_t cur = LSEEK64_(handle, 0, SEEK_CUR);
+	LOFF_T_ cur = LSEEK64_(handle, 0, SEEK_CUR);
 	if(cur < 0) {
 		SetLastError();
 		return;
 	}
-	loff_t len = LSEEK64_(handle, 0, SEEK_END);
+	LOFF_T_ len = LSEEK64_(handle, 0, SEEK_END);
 	if(len < 0) {
 		SetLastError();
 		LSEEK64_(handle, cur, SEEK_SET);
