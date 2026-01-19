From: Santiago Vila <sanvila@debian.org>
Subject: Use format specifier %s to print strings, not the string itself
Bug-Debian: https://bugs.debian.org/673476
X-Debian-version: 3.0-5

From: Florent 'Skia' Jacquet <florent.jacquet@canonical.com>
Subject: Fix buffer overflow when using '-T -TT'
Bug-Debian: https://bugs.debian.org/1093629
Bug-Ubuntu: https://launchpad.net/bugs/2093024
Forwarded: https://sourceforge.net/p/infozip/bugs/81/

strlen(unzip_path) + strlen(zipname) + " " + "'" + "'" + '\0'
The additional space required in the `cmd` buffer is 4, not 3.

--- zip.c.orig	2008-07-05 16:34:06 UTC
+++ zip.c
@@ -1028,7 +1028,7 @@ local void help_extended()
 
   for (i = 0; i < sizeof(text)/sizeof(char *); i++)
   {
-    printf(text[i]);
+    printf("%s", text[i]);
     putchar('\n');
   }
 #ifdef DOS
@@ -1225,7 +1225,7 @@ local void version_info()
             CR_MAJORVER, CR_MINORVER, CR_BETA_VER, CR_VERSION_DATE);
   for (i = 0; i < sizeof(cryptnote)/sizeof(char *); i++)
   {
-    printf(cryptnote[i]);
+    printf("%s", cryptnote[i]);
     putchar('\n');
   }
   ++i;  /* crypt support means there IS at least one compilation option */
@@ -1437,7 +1437,7 @@ local void check_zipfile(zipname, zippath)
     /* Replace first {} with archive name.  If no {} append name to string. */
     here = strstr(unzip_path, "{}");
 
-    if ((cmd = malloc(strlen(unzip_path) + strlen(zipname) + 3)) == NULL) {
+    if ((cmd = malloc(strlen(unzip_path) + strlen(zipname) + 4)) == NULL) {
       ziperr(ZE_MEM, "building command string for testing archive");
     }
 
