--- environ.c.orig Mon Apr  8 11:31:01 2002
+++ environ.c Mon Apr  8 14:06:05 2002
@@ -2721,7 +2721,7 @@
   ps=pe+1;
  } while(*pe!='\0');
  #if SFX_LEVEL==ARJ
-  strcpy(dest, "/usr/bin/arj");
+  strcpy(dest, "/usr/local/bin/arj");
  #elif SFX_LEVEL==ARJSFXV
   strcpy(dest, "./arjsfxv");
  #elif SFX_LEVEL==ARJSFX
