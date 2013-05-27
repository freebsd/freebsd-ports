--- zipmix.c.orig	2013-05-27 12:33:32.795062151 +0200
+++ zipmix.c	2013-05-27 12:33:52.048486869 +0200
@@ -4,6 +4,17 @@ zipmix.exe: zipmix.c; cl zipmix.c /O1 /G
 !if 0
 #endif
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if (defined(BSD) && (BSD >= 199306))
+#include <stdlib.h>
+
+#define min(a,b) MIN(a,b)
+#define max(a,b) MAX(a,b)
+#endif
+
 #if defined(_WIN32)
 
 #include <windows.h>
@@ -167,10 +178,11 @@ void showhelp ()
 }
 
 enum { BOOL_NONE=0,BOOL_OR,BOOL_AND,BOOL_SUB };
-int main (long argc, char **argv)
+int main (int argc, char **argv)
 {
 	unsigned long leng[2];
-	long i, j, k, l, fileng[3], score[4], fmax, ftell43;
+	int i;
+	long j, k, l, fileng[3], score[4], fmax, ftell43;
 	long filespecified = 0, boolop = BOOL_NONE, quiet = 0, overwriteyesmode = 0;
 	short s;
 	char ch, *cptr, *cptr2;
