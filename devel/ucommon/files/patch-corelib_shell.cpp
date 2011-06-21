--- corelib/shell.cpp.orig	2011-06-21 15:59:26.000000000 +0200
+++ corelib/shell.cpp	2011-06-21 16:03:35.000000000 +0200
@@ -19,6 +19,7 @@
 #include <ucommon/string.h>
 #include <ucommon/memory.h>
 #include <ucommon/shell.h>
+#include <stdio.h>
 #include <stdlib.h>
 #include <stdarg.h>
 #ifdef  HAVE_UNISTD_H
@@ -1817,7 +1818,7 @@
     fputs(prompt, stdout);
 
     while(pos < size - 1) {
-        buffer[pos] = ::getchar();
+        buffer[pos] = getchar();
         if(buffer[pos] == '\r' || buffer[pos] == '\n')
             break;
         else if(buffer[pos] == '\b' && pos) {
@@ -1869,7 +1870,7 @@
     noecho(1);
     if(prompt)
         fputs(prompt, stdout);
-    int ch = ::getchar();
+    int ch = getchar();
     echo(1);
 
     return ch;
