--- src/libmdb/backend.c	Tue Dec 10 18:35:25 2002
+++ src/libmdb/backend.c	Tue Apr  8 16:19:29 2003
@@ -114,6 +114,5 @@
 {
-char buf[100];
+	static char buf[16];
         if (col_type > 0x10) {
-                // return NULL;
-					sprintf(buf,"type %04x", col_type);
+		snprintf(buf, sizeof(buf), "type %04x", col_type);
                 return buf;
