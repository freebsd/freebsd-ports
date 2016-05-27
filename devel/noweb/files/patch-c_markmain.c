--- c/markmain.c.orig	2006-06-12 21:16:23 UTC
+++ c/markmain.c
@@ -62,7 +62,7 @@ void markup (FILE* in, FILE *out, char *
 #line 121 "markmain.nw"
 print_pair(out, "file", filename);
 print_state(out, Begin, state, count);
-while ((line = getline_expand(in)) != NULL) {
+while ((line = get_line_expand(in)) != NULL) {
     lineno++;
     
 #line 172 "markmain.nw"
