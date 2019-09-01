--- hpscat.c.orig	2019-08-03 11:25:44 UTC
+++ hpscat.c
@@ -62,7 +62,7 @@ open_outfile(s)    /*  returns -1 if can
     if(ofp=fopen(buf,"r")) { /* file exists */
 	fclose(ofp);
 	fprintf(stderr,"output file %s exists...overwrite? ", buf);
-	gets(ans);
+	fgets(buf,256,ans);
 	if(ans[0]=='y')
 	    unlink(buf);
 	else 
