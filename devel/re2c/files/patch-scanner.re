--- ./scanner.re.orig	Thu Aug 26 23:46:32 1999
+++ ./scanner.re	Sat Oct  5 13:27:00 2002
@@ -10,7 +10,7 @@
 
 #define	BSIZE	8192
 
-#define	YYCTYPE		uchar
+#define	YYCTYPE		char
 #define	YYCURSOR	cursor
 #define	YYLIMIT		lim
 #define	YYMARKER	ptr
@@ -25,7 +25,7 @@
     ;
 }
 
-uchar *Scanner::fill(uchar *cursor){
+char *Scanner::fill(char *cursor){
     if(!eof){
 	uint cnt = tok - bot;
 	if(cnt){
@@ -37,7 +37,7 @@
 	    lim -= cnt;
 	}
 	if((top - lim) < BSIZE){
-	    uchar *buf = new uchar[(lim - bot) + BSIZE];
+	    char *buf = new char[(lim - bot) + BSIZE];
 	    memcpy(buf, tok, lim - tok);
 	    tok = buf;
 	    ptr = &buf[ptr - bot];
@@ -68,7 +68,7 @@
 */
 
 int Scanner::echo(ostream &out){
-    uchar *cursor = cur;
+    char *cursor = cur;
     tok = cursor;
 echo:
 /*!re2c
@@ -85,7 +85,7 @@
 
 
 int Scanner::scan(){
-    uchar *cursor = cur;
+    char *cursor = cur;
     uint depth;
 
 scan:
--- ./scanner.cc.orig	Thu Aug 26 23:46:32 1999
+++ ./scanner.cc	Sat Oct  5 13:27:00 2002
@@ -12,7 +12,7 @@
 
 #define	BSIZE	8192
 
-#define	YYCTYPE		uchar
+#define	YYCTYPE		char
 #define	YYCURSOR	cursor
 #define	YYLIMIT		lim
 #define	YYMARKER	ptr
@@ -27,7 +27,7 @@
     ;
 }
 
-uchar *Scanner::fill(uchar *cursor){
+char *Scanner::fill(char *cursor){
     if(!eof){
 	uint cnt = tok - bot;
 	if(cnt){
@@ -39,7 +39,7 @@
 	    lim -= cnt;
 	}
 	if((top - lim) < BSIZE){
-	    uchar *buf = new uchar[(lim - bot) + BSIZE];
+	    char *buf = new char[(lim - bot) + BSIZE];
 	    memcpy(buf, tok, lim - tok);
 	    tok = buf;
 	    ptr = &buf[ptr - bot];
@@ -62,7 +62,7 @@
 
 
 int Scanner::echo(ostream &out){
-    uchar *cursor = cur;
+    char *cursor = cur;
     tok = cursor;
 echo:
 {
@@ -117,7 +117,7 @@
 
 
 int Scanner::scan(){
-    uchar *cursor = cur;
+    char *cursor = cur;
     uint depth;
 
 scan:
