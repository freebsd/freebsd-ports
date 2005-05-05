--- loadparts.cpp.orig	Wed May  4 19:19:33 2005
+++ loadparts.cpp	Wed May  4 19:19:48 2005
@@ -245,7 +245,7 @@
 
 	while ('\\' == line[l-1]) {
             // concat next line(s)
-	    int bufsize = clamp(0U, sizeof(line)-l, sizeof(line)-1);
+	    int bufsize = clamp(0UL, sizeof(line)-l, sizeof(line)-1);
 	    fgets(&line[l-2], bufsize, fp);
 	    if (feof((FILE*)fp)) break;
 	    l = strlen(line);
