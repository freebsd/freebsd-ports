--- mail.c.orig	1998-03-11 10:02:22 UTC
+++ mail.c
@@ -1,5 +1,9 @@
+#include <ctype.h>
 #include <stdio.h>
+#include <string.h>
 
+static int	ks2iso(unsigned char *, FILE *);
+
 /* ------------------------------------------------------
     Search for Starting Mark and print out (ENGLISH) prologue
     mark : Starting Code
@@ -66,9 +70,8 @@ FILE *fpin, *fpout;
 #define SI '\017'
 #define SO '\016'
 
-int ks2iso(ibuf,fpout)
-unsigned char *ibuf;
-FILE *fpout;
+static int
+ks2iso(unsigned char *ibuf, FILE *fpout)
 {
     int mode=ASCII;
     int i=0;
@@ -172,8 +175,8 @@ void (*prwc)();
         if (fgets((char *) ibuf,HDR_BUF_LEN,fpin) == NULL)  /* no message body  */ 
            return(1);                       /* header only (6/8/96)  */
 
-        if ( ! strncasecmp("Content-Type:",iptr,13) || 
-             !strncasecmp("Content-Transfer-Encoding:",iptr,26) ) {
+        if ( ! strncasecmp("Content-Type:", (char *)iptr, 13) || 
+             !strncasecmp("Content-Transfer-Encoding:", (char *)iptr, 26) ) {
              header_switch(iptr,fpout);
              continue;
         }
@@ -186,7 +189,7 @@ void (*prwc)();
             while ( charset[++i]  != NULL ) {
 
                 sprintf(encode_prefix,"=?%s?B?",charset[i]);
-                if (  ! strncasecmp(encode_prefix,iptr,
+                if (  ! strncasecmp(encode_prefix, (char *)iptr,
                 strlen(encode_prefix)) ) {
                     isbqheader=
                     bqheader_decode(&iptr,encode_prefix,Bencode, 
@@ -195,7 +198,7 @@ void (*prwc)();
                 }
 
                 sprintf(encode_prefix,"=?%s?Q?",charset[i]);
-                if (  ! strncasecmp(encode_prefix,iptr,
+                if (  ! strncasecmp(encode_prefix, (char *)iptr,
                 strlen(encode_prefix)) ) {
                     isbqheader=
                     bqheader_decode(&iptr,encode_prefix,Qencode, 
@@ -238,7 +241,7 @@ int outCode;
     unsigned char ibuf[HDR_BUF_LEN],obuf[HDR_BUF_LEN],tbuf[HDR_BUF_LEN];
     unsigned char *iptr, *tptr;
 
-    if ( cp >= HDR_BUF_LEN ) {
+    if ( cp >= (HDR_BUF_LEN-8) ) {
         pr2m(Printwc,fpout,outCode);
         return;
     }
@@ -250,15 +253,15 @@ int outCode;
             return;
         }
         ibuf[cp++] = '\n';
-        ibuf[cp] = NULL;
+        ibuf[cp] = '\0';
         cp = 0;
         iptr = ibuf;
         while (*iptr) {
             tptr = tbuf;
             while (*iptr && *iptr<0x80) fputc(*iptr++,fpout);
             while (*iptr && (*iptr>0x80 || *iptr ==' ')) *tptr++ = *iptr++;
-            *tptr = NULL;
-            if (tbuf[0]!=NULL) {
+            *tptr = '\0';
+            if (tbuf[0]!='\0') {
                 string_to_base64(obuf, tbuf);
                 fprintf(fpout,"=?EUC-KR?B?%s?=",obuf);
             }
@@ -342,12 +345,12 @@ void (*prwc)();
    only checks if there's any whitespace or '?'.
 */
    
-    while (  *iptr && strncmp("?=",iptr,2) && tptr-tbuf < BQ_BUF_SIZE - 2 )  {
+    while (  *iptr && strncmp("?=", (char *)iptr, 2) && tptr-tbuf < BQ_BUF_SIZE - 2 )  {
          if ( isspace(*iptr) || *iptr == '?' ) break;
          *tptr++ = *iptr++;
     }
-    *tptr = NULL;
-    if (  ! strncmp("?=",iptr,2) ) {
+    *tptr = '\0';
+    if (  ! strncmp("?=", (char *)iptr, 2) ) {
         iptr+=2;
         if (  encoding == Bencode) 
             base64_to_string(obuf, tbuf);
@@ -495,7 +498,7 @@ void header_switch(iptr,fpout)
 /* void header_switch(iptr0,fpout,name_len) */
 void header_switch(iptr,fpout)
 /* unsigned char **iptr0; */
-unsigned char *iptr; 
+char *iptr; 
 FILE *fpout;
 /* int  name_len; */
 {
