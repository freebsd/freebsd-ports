--- pho-util.c.orig	Thu Jul 29 03:08:38 2004
+++ pho-util.c	Thu Jul 29 03:11:44 2004
@@ -2,34 +2,51 @@
 #include "pho.h"
 #include <sys/stat.h>
 #include <stdlib.h>
+#include <dirent.h>
 
-
+char *fTableDir=GCIN_TABLE_DIR;
 char phofname[128]="";
-extern char *TableDir;
 u_short idxnum_pho;
 PHO_IDX idx_pho[1403];
 int ch_pho_ofs;
 PHO_ITEM *ch_pho;
 int ch_phoN;
 
+void get_dir(char *tt)
+{
+    strcpy(tt,(char *)getenv("HOME"));
+    strcat(tt,"/.gcin");
+
+    DIR *dir;
+    if ((dir=opendir(tt))==NULL) {
+      char vv[128];
+
+       mkdir(tt,0755);
+       sprintf(vv,"cp %s/* %s", fTableDir, tt);
+       system(vv);
+    }
+    else
+      closedir(dir);
+}
+
 void pho_load()
 {
 #ifndef  NO_PRIVATE_TSIN
   if (!phofname[0]) {
     char tt[128];
 
-    get_gcin_dir(tt);
+    get_dir(tt);
     strcat(tt,"/pho.tab");
     strcpy(phofname,tt);
 
     char vv[128];
     if (access(phofname, W_OK) < 0){
-      sprintf(vv,"cp %s/pho.tab  %s\n", TableDir, tt);
+      sprintf(vv,"cp %s/pho.tab  %s\n", fTableDir, tt);
       system(vv);
     }
 
 #else
-    strcat(strcpy(phofname, TableDir), "pho.tab");
+    strcat(strcpy(phofname, fTableDir), "pho.tab");
 #endif
   }
 
