--- readfile.c.orig	2004-02-07 17:58:44 UTC
+++ readfile.c
@@ -31,7 +31,7 @@ int numberofkanji=0, highestkanji=0, low
 static char *dictname=NULL;
 static char *edictname=NULL;
 
-/* getline:
+/* get_line:
  *	reads a line (from dictionary).
  *	Deals with 8-bit char reads (or attempts to)
  *	Also attempts to deal with the problem of variable line length.
@@ -46,11 +46,11 @@ static char *edictname=NULL;
  *
  *	Used in "readstructs()", below. Also "readedict()"
  *
- *	Note that this expects static global getline_inptr to be NULL
+ *	Note that this expects static global get_line_inptr to be NULL
  *	if we have just started reading a stream;
  */
 
-int getline(FILE *fp,unsigned char *s)
+int get_line(FILE *fp,unsigned char *s)
 {
 	char * val;
 	char *endparse;
@@ -464,7 +464,7 @@ void readedict()
 		lowestkanji = nextindex;
 	}
 
-	while(getline(fp, instring) != 0)
+	while(get_line(fp, instring) != 0)
 	{
 		int instrlen;
 
@@ -668,7 +668,7 @@ void readstructs(){
 		exit(-1);
 	}
 
-	while (getline(fp,instring) != 0) {
+	while (get_line(fp,instring) != 0) {
 		int Kanji;
 		int freq,grade,N,U,H,Q,SKIP;
 		unsigned char *parse;
