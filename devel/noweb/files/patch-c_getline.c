--- c/getline.c.orig	2006-06-12 21:16:23 UTC
+++ c/getline.c
@@ -19,7 +19,7 @@ void new_buffers(void) {
     checkptr(buf2 = (char *) realloc(buf2, buf_size));
 }
 #line 47 "getline.nw"
-char *getline (FILE *fp) {
+char *get_line (FILE *fp) {
 
     
 #line 82 "getline.nw"
@@ -40,11 +40,11 @@ if (buf1==NULL) {
     return buf1;
 }
 #line 62 "getline.nw"
-char *getline_expand (FILE *fp) {
+char *get_line_expand (FILE *fp) {
     char *s, *t;
     int width;
 
-    if (getline(fp)==NULL) return NULL;
+    if (get_line(fp)==NULL) return NULL;
     
 #line 87 "getline.nw"
 if (columnwidth(buf1) > buf_size - 1) {
