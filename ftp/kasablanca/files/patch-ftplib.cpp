--- src/ftplib.cpp.orig	Wed Feb  2 23:31:16 2005
+++ src/ftplib.cpp	Wed Feb  2 23:37:05 2005
@@ -71,6 +71,14 @@
 #define FTPLIB_READ 1
 #define FTPLIB_WRITE 2
 
+#ifndef __USE_LARGEFILE64
+ #define FOPEN fopen
+ #define FSEEKO fseeko
+#else
+ #define FOPEN fopen64
+ #define FSEEKO fseeko64
+#endif
+
 /*
  * Constructor
  */
@@ -1138,8 +1146,8 @@
 		if (typ == FTPLIB_FILE_WRITE) { ac[0] = 'r'; ac[1] = '\0'; }
 		if (mode == ftplib::image) ac[1] = 'b';
 
-		local = fopen64(localfile, ac);
-		if (typ == FTPLIB_FILE_WRITE_APPEND) fseeko64(local,mp_netbuf->offset,SEEK_SET);
+		local = FOPEN(localfile, ac);
+		if (typ == FTPLIB_FILE_WRITE_APPEND) FSEEKO(local,mp_netbuf->offset,SEEK_SET);
 
 		if (local == NULL)
 		{
