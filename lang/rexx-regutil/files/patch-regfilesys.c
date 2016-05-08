--- regfilesys.c.orig	2003-11-03 20:24:14 UTC
+++ regfilesys.c
@@ -114,7 +114,8 @@ int unmapfile(char *buf, int size);
 /* SysFileSearch(target,file,stem, [options]) */
 rxfunc(sysfilesearch)
 {
-    unsigned char *buf, * dptr, *bol, *eol, *eof, *filename, *options,
+    char *filename, *options;
+    unsigned char *buf, * dptr, *bol, *eol, *eof,
                   *lbuf = NULL;
     PRXSTRING stem;
     RXSTRING target;
@@ -141,7 +142,7 @@ rxfunc(sysfilesearch)
 
     /* map the file into memory. Note that if the OS doesn't support memory-
      * mapped I/O, this allocates a buffer and reads the file into it. */
-    if (!(buf = mapfile(filename, &len))) {
+    if (!(buf = (unsigned char *) mapfile((char *) filename, &len))) {
 	rc = 3;
     }
     else {
@@ -195,7 +196,7 @@ rxfunc(sysfilesearch)
                     i = eol - bol;
                     if (i && bol[i-1] == '\r')
                        i--;
-		    if (cha_adddummy(array, bol, i))
+		    if (cha_adddummy(array, (char *) bol, i))
 			rc = 2;
 		}
 		else {
@@ -203,12 +204,12 @@ rxfunc(sysfilesearch)
 		    if (!lbuf)
 			rc = 2;
 		    else {
-			i = sprintf(lbuf, "%d:", lines);
+			i = sprintf((char *) lbuf, "%d:", lines);
                         memcpy(lbuf+i, bol, eol-bol);
                         i += eol - bol;
                         if (lbuf[i-1] == '\r')
                            i--;
-			if (cha_addstr(array, lbuf, i))
+			if (cha_addstr(array, (char *) lbuf, i))
 			    rc = 2;
 		    }
 		}
@@ -222,7 +223,7 @@ rxfunc(sysfilesearch)
         if (lbuf)
            free(lbuf);
 
-        unmapfile(buf, len);
+        unmapfile((char *) buf, len);
     }
 
     result->strlength = sprintf(result->strptr, "%d", rc);
@@ -730,8 +731,8 @@ rxfunc(sysfiletree)
 	rc = 2;
 
     else {
-	/* break the list into directory & pattern, so the input can be of
-	 * the form /usr/home/ptjm/*.c */
+//	break the list into directory & pattern, so the input can be of
+//	the form /usr/home/ptjm/*.c
 
 	dir = pattern;
 	pattern = strrchr(dir, '/');
