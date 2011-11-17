--- use_mase_files.cxx.orig	2011-11-17 14:20:13.000000000 +0100
+++ use_mase_files.cxx	2011-11-17 14:20:01.000000000 +0100
@@ -1457,8 +1457,6 @@
 
 #else
 
-extern "C" { int stat(char *, void *); }
-
 int check_path(char *fname)  
 /* to check for presence of file fname 
 searching for it through all path directories 
@@ -1468,7 +1466,7 @@
 #define Mxdir 200
     char dir[Mxdir+1], *path, *deb, *fin;
     int lf, ltot;
-    static char stat_struct[250]; /* bigger than necessary */
+	 struct stat sb;
     path=getenv("PATH"); 	/* get the list of path directories, 
 				    separated by :
 				*/
@@ -1488,7 +1486,7 @@
 		    dir[ltot]='/';
 		    strcpy(dir+ltot+1,fname); 
 			/* now dir is appended with filename */
-		    if( stat(dir, stat_struct)  == 0) return 0;
+		    if( stat(dir, &sb)  == 0) return 0;
 		    }
 	    deb=fin+1;
 	    }
