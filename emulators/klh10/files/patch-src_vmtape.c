--- src/vmtape.c	2002/01/12 16:47:42	1.1
+++ src/vmtape.c	2002/01/12 16:48:35
@@ -696,13 +696,11 @@
 
     /* Now verify filenames don't already exist */
     if (cfn && (cf = fopen(cfn, "r"))) {
-	fclose(cf);
 	vmterror(t, "Tape control file \"%.256s\" already exists", cfn);
 	goto badret;
     }
 
     if (df = fopen(dfn, "rb")) {
-	fclose(df);
 	vmterror(t, "Tape data file \"%.256s\" already exists", dfn);
 	goto badret;
     }
@@ -714,8 +712,6 @@
 	goto badret;
     }
     if (!(df = fopen(dfn, "w+b"))) {
-	fclose(df);
-	if (cfn) fclose(cf);
 	vmterror(t, "Cannot create tape data file \"%.256s\": %.80s",
 		 dfn, os_strerror(errno));
 	goto badret;
