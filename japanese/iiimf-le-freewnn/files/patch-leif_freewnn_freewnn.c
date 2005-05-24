--- leif/freewnn/freewnn.c.orig	Sun Mar 20 11:41:29 2005
+++ leif/freewnn/freewnn.c	Wed May 18 01:20:56 2005
@@ -59,7 +59,7 @@
 #define BUFSIZE 1024
 #endif
 
-#define WNNRCFILE "/etc/FreeWnn/ja/wnnenvrc"
+#define WNNRCFILE "%%LOCALBASE%%" "/lib/wnn/ja_JP/wnnenvrc"
 
 #define CSC_OPEN_LOCALE "csconv_open_locale"
 #define CSC_OPEN        "csconv_open"
@@ -162,7 +162,7 @@
   int count = 0;
 
   if( str == NULL ) return NULL;
-  if( *str == '\0' ) return NULL;
+  if( *str == '\0' ) return "";
 
   for(i=0;i<strlen(str);i++) {
     count++;
@@ -201,7 +201,7 @@
 
   if( wstr == NULL ) return NULL;
 
-  if( *wstr == 0 ) return NULL;
+  if( *wstr == 0 ) return "";
 
   for(i=0;wstr[i] != 0;i++) 
     count++;
@@ -388,14 +388,14 @@
 
 UTFCHAR*
 UTF8_to_UTFCHAR(unsigned char* str) {
-  UTFCHAR *p, *ustr = NULL;
+  UTFCHAR *ustr = NULL;
   int len, ulen;
 
   const char *csc_arg_str_ccp; /* For compiler optimization */
   char *csc_arg_str_cp; /* For compiler optimization */
 
   if( str == NULL ) return NULL;
-  if( *str == '\0' ) return NULL;
+  if( *str == '\0' ) return "";
 
   if( csconv_utf8_cd == NULL ) {
     csconv_utf8_cd = csc_open("UTF-16", "UTF-8");
@@ -408,30 +408,34 @@
   len = strlen(str);
 
   ulen = sizeof(UTFCHAR)*(len+1);
-  p = ustr = (UTFCHAR*)calloc(len+1, sizeof(UTFCHAR));
+  ustr = (UTFCHAR*)malloc(ulen);
+  if (!ustr) return NULL;
+  memset(ustr, 0, ulen);
+  ulen--;
 
   /* Below 2 lines are to prevent gcc's warning and for the sake
      of compiler optimization */
   csc_arg_str_ccp = (const char*)str;
   csc_arg_str_cp = (char*)ustr;
 
-  csc_conv(csconv_utf8_cd, &csc_arg_str_ccp, &len, &csc_arg_str_cp, &ulen);
-
-  *ustr = 0;
+  if ((size_t)-1 == csc_conv(csconv_utf8_cd, &csc_arg_str_ccp, &len, &csc_arg_str_cp, &ulen)) {
+    free(ustr);
+    return NULL;
+  }
 
-  return p;
+  return ustr;
 }
 
 UTFCHAR*
 euc2UTFCHAR(unsigned char* str) {
-  UTFCHAR *p, *ustr = NULL;
+  UTFCHAR *ustr = NULL;
   int len, ulen;
 
   const char *csc_arg_str_ccp; /* For compiler optimization */
   char *csc_arg_str_cp; /* For compiler optimization */
 
   if( str == NULL ) return NULL;
-  if( *str == '\0' ) return NULL;
+  if( *str == '\0' ) return "";
 
   if( csconv_cd == NULL ) {
     csconv_cd = csc_open_locale("ja_JP.eucJP", "UTF-16", "MultiByte");
@@ -444,18 +448,22 @@
   len = strlen(str);
 
   ulen = sizeof(UTFCHAR)*(len+1);
-  p = ustr = (UTFCHAR*)calloc(len+1, sizeof(UTFCHAR));
+  ustr = (UTFCHAR*)malloc(ulen);
+  if (!ustr) return NULL;
+  memset(ustr, 0, ulen);
+  ulen--;
 
   /* Below 2 lines are to prevent gcc's warning and for the sake
      of compiler optimization */
   csc_arg_str_ccp = (const char*)str;
   csc_arg_str_cp = (char*)ustr;
 
-  csc_conv(csconv_cd, &csc_arg_str_ccp, &len, &csc_arg_str_cp, &ulen);
-
-  *ustr = 0;
+  if ((size_t)-1 == csc_conv(csconv_cd, &csc_arg_str_ccp, &len, &csc_arg_str_cp, &ulen)) {
+    free(ustr);
+    return NULL;
+  }
 
-  return p;
+  return ustr;
 }
 
 IMText*
@@ -466,7 +474,10 @@
   ustr = UTF8_to_UTFCHAR(str);
 
   p = create_IMText(s, ustrlen(ustr));
-  memcpy(p->text.utf_chars, ustr, (ustrlen(ustr)+1)*sizeof(UTFCHAR));
+  if (p && ustr) {
+    memcpy(p->text.utf_chars, ustr, (ustrlen(ustr)+1)*sizeof(UTFCHAR));
+  }
+  if (ustr) free(ustr);
 
   return p;
 }
@@ -479,7 +490,10 @@
   ustr = euc2UTFCHAR(str);
 
   p = create_IMText(s, ustrlen(ustr));
-  memcpy(p->text.utf_chars, ustr, (ustrlen(ustr)+1)*sizeof(UTFCHAR));
+  if (p && ustr) {
+    memcpy(p->text.utf_chars, ustr, (ustrlen(ustr)+1)*sizeof(UTFCHAR));
+  }
+  if (ustr) free(ustr);
 
   return p;
 }
