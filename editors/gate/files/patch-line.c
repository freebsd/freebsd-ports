--- line.c.orig	2003-06-19 15:06:54 UTC
+++ line.c
@@ -82,7 +82,7 @@ void mcursor(int *col, int *lin, char ch
  * If <wbuf> is NULL, then this does a more ordinary, wrapless read.
  */
 
-int getline(char *buf, char *wbuf, int *wcol, char *prompt)
+int get_line(char *buf, char *wbuf, int *wcol, char *prompt)
 {
     int linemode= (wbuf == NULL);	/* reading single line, not file */
     int wrapon= !linemode;	        /* is line wrap enabled? */
