--- ./files.c.orig	2013-06-11 14:21:06.504446578 +0200
+++ ./files.c	2013-06-11 14:23:44.928830892 +0200
@@ -340,6 +340,17 @@
 
 	assert(place != NULL);
 
+	if (name[0] == '/') {
+		fd = file_tryopen(name);
+		if (fd >= 0) {
+			pf = place_addfile(place, name, true);
+			file_read(pf, fd, name, false);
+			close(fd);
+			return;
+		}
+		complain(place, "Include file %s not found", name);
+		complain_fail();
+	}
 	num = incdirarray_num(path);
 	for (i=0; i<num; i++) {
 		id = incdirarray_get(path, i);
