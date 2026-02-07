--- src/net.c.orig	Thu Dec 24 06:24:50 1998
+++ src/net.c	Thu Jun 17 09:52:06 2004
@@ -537,12 +537,10 @@
    pointer, precede with a socket number */
 /* please stop using this one except for server output.  dcc output
    should now use dprintf(idx,"format",[params]);   */
-void tprintf(va_alist)
-va_dcl
+void tprintf(int sock, char *format, ...)
 {
-  char *format; int sock; va_list va; static char SBUF2[1050];
-  va_start(va);
-  sock=va_arg(va,int); format=va_arg(va,char *);
+  va_list va; static char SBUF2[1050];
+  va_start(va, format);
   vsprintf(SBUF2,format,va);
   if (strlen(SBUF2)>1022)
  {  
