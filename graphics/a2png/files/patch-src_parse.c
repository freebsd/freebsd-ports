--- src/parse.c.orig	2006-10-05 13:36:26 UTC
+++ src/parse.c
@@ -22,9 +22,8 @@ void scan_rgb(const char* s, rgb_t* color) {
 
 // returns 1 if not EOF, 0 if EOF
 // see note in parse_html for a rationale of this rather odd tokenizer function
-inline
 int fgettok(FILE *f, char* buf, size_t buflen) {
-	char c;
+	int c;
 
 	// read until we get start of a token
 	do {
