--- vertex/disk.cpp.orig	Mon Nov  1 12:34:51 2004
+++ vertex/disk.cpp	Tue Jun 19 01:39:05 2007
@@ -112,11 +112,7 @@
 	if(strptr == NULL)
 	{
 	    /* No drive notation, check if first char is a '\\' */
-#if defined(__cplusplus) || defined(c_plusplus)
 	    while(ISBLANK(*path))
-#else
-	    while(ISBLANK((int)(*path)))
-#endif
 		path++;
 
 	    return(*path == '\\');
@@ -130,12 +126,7 @@
 	if(path == NULL)
 	    return(0);
 
-	// Dan S: typecast is due to const.
-#if defined(__cplusplus) || defined(c_plusplus)
-	while(ISBLANK(reinterpret_cast<char>(*path)))
-#else
 	while(ISBLANK(*path))
-#endif
 	    path++;
 
 	return(*path == DIR_DELIMINATOR);
