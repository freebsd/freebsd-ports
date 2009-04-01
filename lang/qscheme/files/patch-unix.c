--- unix.c.orig	2009-03-03 18:14:22.000000000 +0200
+++ unix.c	2009-03-03 18:17:18.000000000 +0200
@@ -283,12 +283,14 @@
 
 #define SCM_DIRP(x)		(SCM_OBJTYPE(x) == SOBJ_T_DIR)
 #define SCM_DIR(x)		(DIR *)SCM_AUX(x)
+#define SCM_DIR_SET		SCM_AUX_SET
 
 void scm_dir_sweep(SOBJ x)
 {
   if (SCM_DIR(x) != NULL) {
 	closedir(SCM_DIR(x));
-	SCM_DIR(x) = NULL;
+	/*SCM_DIR(x) = NULL;*/
+	SCM_DIR_SET(x, NULL);
   }
 }
 
@@ -300,7 +302,8 @@
   if (!SCM_STRINGP(name))	SCM_ERR("bad dir name", name);
   if ((dir = opendir(SCM_STR_VALUE(name))) != NULL) {
 	new = scm_newcell(SOBJ_T_DIR);
-	SCM_DIR(new) = dir;
+	/*SCM_DIR(new) = dir;*/
+	SCM_DIR_SET(new, dir);
 	return(new);
   }
   return(scm_false);
@@ -312,7 +315,8 @@
   if (!SCM_DIRP(dir))	SCM_ERR("bad dir", dir);
   if (SCM_DIR(dir) == NULL) SCM_ERR("already closed", dir);
   r = closedir(SCM_DIR(dir));
-  SCM_DIR(dir) = NULL;
+  /*SCM_DIR(dir) = NULL;*/
+  SCM_DIR_SET(dir, NULL);
   return(SCM_MKBOOL(r == 0));
 }
 
