--- leif/freewnn/freewnn.c.orig	Mon Oct  4 19:13:52 2004
+++ leif/freewnn/freewnn.c	Sun Feb 20 15:43:20 2005
@@ -59,9 +59,9 @@
 #define BUFSIZE 1024
 #endif
 
-#define WNNRCFILE "/etc/FreeWnn/ja/wnnenvrc"
+#define WNNRCFILE (LOCALBASE "/lib/wnn/ja_JP/wnnenvrc")
 
-#define CSC_PATH "/usr/lib/im/csconv/csconv.so"
+#define CSC_PATH (IMDIR "/csconv/csconv.so")
 #define CSC_OPEN_LOCALE "csconv_open_locale"
 #define CSC_OPEN        "csconv_open"
 #define CSC_CONV        "csconv"
@@ -163,7 +163,7 @@
   int count = 0;
 
   if( str == NULL ) return NULL;
-  if( *str == '\0' ) return NULL;
+  if( *str == '\0' ) return "";
 
   for(i=0;i<strlen(str);i++) {
     count++;
@@ -202,7 +202,7 @@
 
   if( wstr == NULL ) return NULL;
 
-  if( *wstr == 0 ) return NULL;
+  if( *wstr == 0 ) return "";
 
   for(i=0;wstr[i] != 0;i++) 
     count++;
