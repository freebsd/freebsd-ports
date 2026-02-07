--- src/lib.c.orig	2003-07-11 16:34:46 UTC
+++ src/lib.c
@@ -76,9 +76,9 @@ static int _init_upper()
 		upper[c] = 'A' + (c - 'a');
 
 	DEBUG( fprintf (stderr, "init umlaute\n"); )
-	upper[c = (unsigned char) 'ä'] = 'Ä';
-	upper[c = (unsigned char) 'ö'] = 'Ö';
-	upper[c = (unsigned char) 'ü'] = 'Ü';
+	upper[c = (unsigned char) '\xe4'] = '\xc4';
+	upper[c = (unsigned char) '\xf6'] = '\xd6';
+	upper[c = (unsigned char) '\xfc'] = '\xdc';
 
 	DEBUG( fprintf (stderr, "init upper[] complete\n"); )
 	return (0);
@@ -97,9 +97,9 @@ static int _init_lower()
 		lower[c] = 'a' + (c - 'A');
 
 	DEBUG( fprintf (stderr, "init umlaute\n"); )
-	lower[c = (unsigned char) 'Ä'] = 'ä';
-	lower[c = (unsigned char) 'Ö'] = 'ö';
-	lower[c = (unsigned char) 'Ü'] = 'ü';
+	lower[c = (unsigned char) '\xc4'] = '\xe4';
+	lower[c = (unsigned char) '\xd6'] = '\xf6';
+	lower[c = (unsigned char) '\xdc'] = '\xfc';
 
 	DEBUG( fprintf (stderr, "init upper[] complete\n"); )
 	return (0);
@@ -140,8 +140,8 @@ int islowercase(unsigned int c)
 
 char *strlwr(char *string)
 {
-	unsigned int c;
-	unsigned char *p;
+	char c;
+	char *p;
 
 	if (lower['0'] == 0)
 		_init_lower();
@@ -156,8 +156,8 @@ char *strlwr(char *string)
 
 char *strupr(char *string)
 {
-	unsigned int c;
-	unsigned char *p;
+	char c;
+	char *p;
 
 	if (upper['0'] == 0)
 		_init_upper();
@@ -183,7 +183,7 @@ char *skip_ws(char *string)
 char *noctrl(char *buffer)
 {
 	int	len, i;
-	unsigned char *p;
+	char *p;
 
 	if ((p = buffer) == NULL)
 		return (NULL);
@@ -201,8 +201,8 @@ char *noctrl(char *buffer)
 
 char *get_word(char **from, char *to, int maxlen)
 {
-	unsigned int c;
-	unsigned char *p;
+	char c;
+	char *p;
 	int	k;
 
 	maxlen -= 2;
