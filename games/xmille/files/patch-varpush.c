--- varpush.c.orig	Wed Jul  8 11:33:36 1987
+++ varpush.c	Fri Jun 15 02:20:34 2007
@@ -1,3 +1,5 @@
+#include	<stdio.h>
+#include	<string.h>
 # include	"mille.h"
 
 /*
@@ -6,6 +8,13 @@
 
 int	read(), write();
 
+static void remove_terminating_newline( char* buf )
+{
+    int len = strlen(buf);
+    if ( buf[len-1] == '\n' )
+	buf[len-1] = 0;
+}
+
 /*
  *	push variables around via the routine func() on the file
  * channel file.  func() is either read or write.
@@ -36,7 +45,8 @@
 			char	buf[80];
 over:
 			printf("Debug file:");
-			gets(buf);
+			fgets(buf,80,stdin);
+			remove_terminating_newline(buf);
 			if ((outf = fopen(buf, "w")) == NULL) {
 				perror(buf);
 				goto over;
