
$FreeBSD$

--- search.c.orig	Sun Oct  5 02:38:32 2003
+++ search.c	Sun Oct  5 02:40:32 2003
@@ -769,8 +769,12 @@
 
 int do_gotoline(int line, int save_pos)
 {
+    static char *linestr = NULL;
+
+    linestr = mallocstrcpy(linestr, answer);
+
     if (line <= 0) {		/* Ask for it */
-	int st = statusq(FALSE, goto_list, line != 0 ? answer : "",
+	int st = statusq(FALSE, goto_list, line != 0 ? linestr : "",
 #ifndef NANO_SMALL
 			NULL,
 #endif
