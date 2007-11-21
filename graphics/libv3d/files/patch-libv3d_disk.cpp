--- libv3d/disk.cpp.orig	2007-11-16 12:27:26.000000000 +0100
+++ libv3d/disk.cpp	2007-11-16 12:30:59.000000000 +0100
@@ -120,12 +120,7 @@
 	if(path == NULL)
             return(0);
 
-	// Dan S: typecast is due to const.
-#if defined(__cplusplus) || defined(c_plusplus)
-	while(ISBLANK(reinterpret_cast<char>(*path)))
-#else
 	while(ISBLANK(*path))
-#endif
 	    path++;
 
 	return((*path) == DIR_DELIMINATOR);
@@ -440,7 +435,7 @@
         /* Get enviroment value of HOME. */
         strptr = getenv("HOME");
         if(strptr == NULL)
-            strptr = "/";
+            strptr = (char *)"/";
 
         /* Copy input path to return path. */
         strncpy(rtn_path, path, PATH_MAX);
@@ -1006,7 +1001,7 @@
            (child == NULL) ||
            (parent == child)
         )
-            return("/");
+            return((char *)"/");
 
         /* If child is absolute, copy child and return. */
         if((*child) == DIR_DELIMINATOR)
@@ -1245,7 +1240,7 @@
 
 
         if(path == NULL)
-            return("/");
+            return((char *)"/");
 
         i = 0;
         strptr1 = path;
