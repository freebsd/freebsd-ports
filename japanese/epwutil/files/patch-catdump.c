--- catdump.c.orig	2016-05-13 19:10:22 UTC
+++ catdump.c
@@ -201,7 +201,7 @@ void	outhex();
 void	outstr();
 void	outjstr();
 int	undump();
-uchr	*getline();
+uchr	*get_line();
 uchr	*getvalue();
 int	gethex();
 int	hexdigit();
@@ -561,7 +561,7 @@ char	*txtfile, *catalog;
     err = 0;
     line = 0;
 
-    if (getline(buf, fp) == NULL ||
+    if (get_line(buf, fp) == NULL ||
 	strncmp(buf, CAT_ENTRY, strlen(CAT_ENTRY))) {
 	fprintf(stderr, "ERR: 項目 %s がありません\n", CAT_ENTRY);
 	fclose(fp);
@@ -571,7 +571,7 @@ char	*txtfile, *catalog;
     st = 0;
     hdr = (HDR_T *)catbuf;
     mask = 0L;
-    while (getline(buf, fp) != NULL && *buf != '[') {
+    while (get_line(buf, fp) != NULL && *buf != '[') {
 	if ((p = getvalue(buf)) == NULL) {
 	    fprintf(stderr, "ERR: line %d: 構文に誤りがあります\n", line);
 	    err++;
@@ -666,7 +666,7 @@ char	*txtfile, *catalog;
 	if (strncmp(buf, BOOK_ENTRY, strlen(BOOK_ENTRY))) {
 	    fprintf(stderr, "ERR: line %d: 不明な項目です(%s)\n", line, buf);
 	    err++;
-	    while (getline(buf, fp) != NULL && *buf != '[')
+	    while (get_line(buf, fp) != NULL && *buf != '[')
 		;
 	    if (*buf == '\0')
 		break;
@@ -680,7 +680,7 @@ char	*txtfile, *catalog;
 	    break;
 	}
 	mask = 0;
-	while (getline(buf, fp) != NULL && *buf != '[') {
+	while (get_line(buf, fp) != NULL && *buf != '[') {
 	    if ((p = getvalue(buf)) == NULL) {
 		fprintf(stderr, "ERR: line %d: 構文に誤りがあります\n", line);
 		err++;
@@ -917,7 +917,7 @@ char	*txtfile, *catalog;
 }
 
 uchr *
-getline(buf, fp)
+get_line(buf, fp)
 uchr	*buf;
 FILE	*fp;
 {
