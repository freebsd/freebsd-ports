--- autogb.c.orig	Mon Apr 23 22:18:06 2001
+++ autogb.c	Wed Oct 15 17:28:48 2003
@@ -34,15 +34,14 @@
 void print_help(char* filename){
 	printf("\nUsage: %s [-OPTION] < input > output\n", filename);
 	puts(
-"Now autoconvert can only judge gb/big5/hz encoding, so if you want to 
-do other conversion, you must set the option --input.  Without --input,
-the program will guess the encoding of the input.
-OPTION is one of (case insensitive):
-  -i encoding, --input encoding:			Set the input encoding
-  -o encoding, --output encoding:			Set the output encoding
-
-  The encoding should be gb, big5, hz, uni, utf7 or utf8.
-	");
+"Now autoconvert can only judge gb/big5/hz encoding, so if you want to "
+"do other conversion, you must set the option --input.  Without --input,"
+"the program will guess the encoding of the input."
+"OPTION is one of (case insensitive):"
+"  -i encoding, --input encoding:			Set the input encoding"
+"  -o encoding, --output encoding:			Set the output encoding"
+"  The encoding should be gb, big5, hz, uni, utf7 or utf8."
+"	");
 
 	exit(0);
 }
