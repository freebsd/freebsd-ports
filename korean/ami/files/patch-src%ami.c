--- src/ami.c.orig	Mon Feb 17 20:49:11 2003
+++ src/ami.c	Mon Feb 17 20:50:09 2003
@@ -403,13 +403,14 @@
     }
 
     codeset=nl_langinfo(CODESET);
-    if ( ! strcasecmp(codeset,"EUC-KR") ) 
+    if ( ! strcasecmp(codeset,"EUC") ||
+         ! strcasecmp(codeset,"eucKR") ) 
        ami_codeset=AMI_EUC;
     else if ( ! strcasecmp(codeset,"UTF-8") )
        ami_codeset=AMI_UTF8;
     else {
        g_print(_("The locale codeset is %s. It must be either "
-               "EUC-KR or UTF-8.\n Check your locale.\n"),
+               "eucKR or UTF-8.\n Check your locale.\n"),
                codeset);
        exit(1); 
     }
