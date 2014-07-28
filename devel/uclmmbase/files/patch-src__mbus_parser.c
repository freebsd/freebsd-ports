--- src/mbus_parser.c	2006-09-13 13:36:11.000000000 -0400
+++ src/mbus_parser.c	2011-03-13 20:17:35.000000000 -0400
@@ -159,4 +159,5 @@
 {
 	char	*p;
+	long	 l;
 
 	assert(m->magic == MBUS_PARSER_MAGIC);
@@ -167,10 +168,11 @@
         }
 
-	*i = (int) strtol(m->buffer, &p, 10);
-	if (errno == ERANGE) {
-		debug_msg("integer out of range: %d\n", *i);
+	l = strtol(m->buffer, &p, 10);
+	if (l > INT_MAX || l < INT_MIN || errno == ERANGE) {
+		debug_msg("integer out of range: %s\n", m->buffer);
 		abort();
 		return FALSE;
 	}
+	*i = l;
 
 	if (p == m->buffer) {
