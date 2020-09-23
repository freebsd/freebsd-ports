--- mmix-config.w.orig	2014-11-20 17:38:57 UTC
+++ mmix-config.w
@@ -357,7 +357,7 @@ print error messages.
 
 @<Global variables@>=
 FILE *config_file; /* input comes from here */
-char buffer[BUF_SIZE]; /* input lines go here */
+extern char buffer[BUF_SIZE]; /* input lines go here */
 char token[BUF_SIZE]; /* and tokens are copied to here */
 char *buf_pointer=buffer; /* this is our current position */
 bool token_prescanned; /* does |token| contain the next token already? */
