--- kakasi.c~	Sun Jan 23 19:16:28 2000
+++ kakasi.c	Wed Mar 14 15:26:42 2001
@@ -70,7 +70,9 @@
     while (i < RSTRING(src)->len) {
       if (*(RSTRING(src)->ptr + i) != '\0') {
 	buf = kakasi_do((RSTRING(src)->ptr + i));
-	rb_str_concat(dst, rb_str_new2(buf));
+	if (buf) {
+	  rb_str_concat(dst, rb_str_new2(buf));
+	}
 	free(buf);
 	while (*(RSTRING(src)->ptr + i) != '\0') {
 	  i++;
