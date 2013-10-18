--- src/io/inkjar.cpp.orig	2013-10-16 23:28:46.000000000 +0200
+++ src/io/inkjar.cpp	2013-10-16 23:34:00.000000000 +0200
@@ -44,6 +44,7 @@
 
 #include <cstring>
 #include <string>
+#include <cstdio>
 #include <cstdlib>
 #include <glib.h>
 #include <zlib.h>
@@ -68,7 +69,7 @@
 {
     _filename = g_strdup(new_filename);
     _last_filename = NULL;
-    fd = -1;
+    fd = NULL;
 }
 
 //fixme: the following should probably just return a const gchar* and not 
@@ -104,7 +105,7 @@
 
 bool JarFile::open()
 {
-    if ((fd = ::open(_filename, O_RDONLY)) < 0) {
+    if ((fd = fopen(_filename, O_RDONLY)) < 0) {
 	fprintf(stderr, "open failed.\n");
 	return false;
     }
@@ -116,7 +117,7 @@
 
 bool JarFile::close()
 {
-    if (fd >= 0 && !::close(fd)) {
+    if (fd >= 0 && !fclose(fd)) {
 	inflateEnd(&_zs);
 	return true;
     }
@@ -256,7 +257,7 @@
     
     if (method == 8 || flags & 0x0008) {
 	unsigned int file_length = 0;//uncompressed file length
-	lseek(fd, eflen, SEEK_CUR);
+	fseek(fd, eflen, SEEK_CUR);
 	guint8 *file_data = get_compressed_file(compressed_size, file_length, 
 						crc, flags);
 	if (file_data == NULL) {
@@ -274,7 +275,7 @@
 	}
 	g_byte_array_append(gba, file_data, compressed_size);
     } else {
-	lseek(fd, compressed_size+eflen, SEEK_CUR);
+	fseek(fd, compressed_size+eflen, SEEK_CUR);
 	g_byte_array_free(gba, FALSE);
 	return NULL;
     }
@@ -313,7 +314,7 @@
 	std::printf("%d bytes written\n", out_a);
 #endif
     }
-    lseek(fd, eflen, SEEK_CUR);
+    fseek(fd, eflen, SEEK_CUR);
     g_free(bytes);
 
     if (!check_crc(crc, crc2, flags)) {
@@ -328,7 +329,7 @@
 int JarFile::read(guint8 *buf, int count)
 {
     int nbytes;
-    if ((nbytes = ::read(fd, buf, count)) != count) {
+    if ((nbytes = fread(buf, 1, count, fd)) != count) {
 	fprintf(stderr, "read error\n");
 	exit(1);
 	return 0;
@@ -357,9 +358,8 @@
 		
 	if (!_zs.avail_in) {
 	
-	    if ((nbytes = ::read(fd, in_buffer, 
-				 (leftover_in < RDSZ ? leftover_in : RDSZ))) 
-		< 0) {
+	    if ((nbytes = fread(in_buffer, 1, 
+		(leftover_in < RDSZ ? leftover_in : RDSZ), fd)) < 0) {
 		fprintf(stderr, "jarfile read error");
 	    }
 	    _zs.avail_in = nbytes;
@@ -537,7 +537,7 @@
 		}
 	    }
 	} else if (gba->len > 0)
-	    ::write(1, gba->data, gba->len);
+	    fwrite(gba->data, 1, gba->len, stdout);
 	else
 	    break;
     }
