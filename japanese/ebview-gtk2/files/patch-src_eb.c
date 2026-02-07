--- src/eb.c.orig	2014-12-22 16:50:58.000000000 +0900
+++ src/eb.c	2014-12-22 16:54:43.000000000 +0900
@@ -674,7 +674,8 @@
 	EB_Error_Code error_code=EB_SUCCESS;
 	EB_Position text_position;
 	char data[EB_SIZE_PAGE+4];
-	int i, length;
+	int i;
+	ssize_t length;
 
 	int start_page;
 	int end_page;
@@ -856,7 +857,8 @@
 	char data[EB_SIZE_PAGE];
 	char *jisword;
 	char *word_p;
-	int i, length;
+	int i;
+	ssize_t length;
 	char *p;
 	char heading[MAXLEN_TEXT + 1];
 	RESULT *rp;
@@ -1053,7 +1055,7 @@
 	char data[EB_SIZE_PAGE];
 	char *jisword;
 	char *word_p;
-	int length;
+	ssize_t length;
 	char *p;
 	char heading[MAXLEN_TEXT + 1];
 	RESULT *rp;
@@ -1679,7 +1681,8 @@
 gint ebook_simple_search2(BOOK_INFO *binfo, char *word, gint method, gchar *title)
 {
 	EB_Error_Code error_code=EB_SUCCESS;
-	int i, len, total_hits=0;
+	int i, total_hits=0;
+        ssize_t len;
 	EB_Hit hits[MAX_HITS];
 	int hitcount;
 	char heading[MAXLEN_HEADING + 1];
@@ -1988,7 +1991,7 @@
 gchar *ebook_get_heading(BOOK_INFO *binfo, int page, int offset)
 {
 	EB_Error_Code error_code;
-	int len;
+	ssize_t len;
 	char heading[MAXLEN_HEADING + 1];
 	EB_Position position;
 	gchar *p;
@@ -2021,7 +2024,7 @@
 
 gchar *ebook_get_text(BOOK_INFO *binfo, int page, int offset){
 	EB_Error_Code error_code;
-	int len;
+	ssize_t len;
 	char text[MAXLEN_TEXT + 1];
 	EB_Position position;
 	gchar *p;
@@ -2064,7 +2067,7 @@
 gchar *ebook_get_candidate(BOOK_INFO *binfo, int page, int offset)
 {
 	EB_Error_Code error_code;
-	int len;
+	ssize_t len;
 	char text[MAXLEN_TEXT + 1];
 	EB_Position position;
 	gchar *p;
