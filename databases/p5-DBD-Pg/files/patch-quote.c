diff -ru quote.c~ quote.c
--- quote.c~	Sun Jan  2 20:01:43 2005
+++ quote.c	Sun Jan  2 20:04:39 2005
@@ -9,7 +9,7 @@
 {
 	const char *source = from;
 	char	   *target = to;
-	unsigned int remaining = length;
+	unsigned size_t remaining = length;
 
 	while (remaining > 0)
 	{
@@ -146,9 +146,9 @@
 unsigned char *
 PQunescapeBytea2(const unsigned char *strtext, size_t *retbuflen)
 {
-	size_t strtextlen, buflen;
+	size_t strtextlen, buflen, i, j;
 	unsigned char *buffer, *tmpbuf;
-	int i, j, byte;
+	int byte;
 
 	if (strtext == NULL) {
 		return NULL;
@@ -393,7 +393,7 @@
 {
 	char *result;
 	char *dest;
-	int max_len = 0, i;
+	size_t max_len = 0, i;
 
 	/* We are going to retun a quote_bytea() for backwards compat but
 	   we warn first */
@@ -483,7 +483,7 @@
 void
 dequote_char(string, retlen)
 	char *string;
-	int *retlen;
+	size_t *retlen;
 {
 	/* TODO: chop_blanks if requested */
 	*retlen = strlen(string);
@@ -493,7 +493,7 @@
 void
 dequote_varchar (string, retlen)
 	char *string;
-	int *retlen;
+	size_t *retlen;
 {
 	*retlen = strlen(string);
 }
@@ -503,7 +503,7 @@
 void
 dequote_bytea(string, retlen)
 	char *string;
-	int *retlen;
+	size_t *retlen;
 {
 	char *s, *p;
 	int c1,c2,c3;
@@ -542,7 +542,7 @@
 void
 dequote_sql_binary (string, retlen)
 	char *string;
-	int *retlen;
+	size_t *retlen;
 {
 	/* We are going to retun a dequote_bytea(), JIC */
 	warn("Use of SQL_BINARY invalid in dequote()");
@@ -556,7 +556,7 @@
 void
 dequote_bool (string, retlen)
 	char *string;
-	int *retlen;
+	size_t *retlen;
 {
 	switch(*string){
 		case 'f': *string = '0'; break;
