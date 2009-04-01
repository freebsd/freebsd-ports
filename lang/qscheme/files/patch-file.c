--- file.c.orig	2009-03-03 17:38:43.000000000 +0200
+++ file.c	2009-03-03 17:40:53.000000000 +0200
@@ -7,11 +7,13 @@
 
 #define SCM_FILE(x)		(FILE *)(SCM_AUX(x))
 #define SCM_FILEP(x)	(SCM_OBJTYPE(x) == SOBJ_T_FILE)
+#define SCM_FILE_SET	SCM_AUX_SET
 
 SOBJ scm_file_new(FILE *fp)
 {
   SOBJ new = scm_newcell(SOBJ_T_FILE);
-  SCM_FILE(new) = fp;
+  /*SCM_FILE(new) = fp;*/
+  SCM_FILE_SET(new, fp);
   return(new);
 }
 
@@ -77,7 +79,8 @@
   int r;
   if (!SCM_FILEP(x))		SCM_ERR("bad file", x);
   r = fclose(SCM_FILE(x));
-  SCM_FILE(x) = NULL;
+  /*SCM_FILE_SET(x) = NULL;*/
+  SCM_FILE_SET(x, NULL);
   return(SCM_MKINUM(r));
 }
 
