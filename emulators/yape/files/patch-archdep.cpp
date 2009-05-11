
$FreeBSD$

--- archdep.cpp.orig
+++ archdep.cpp
@@ -75,7 +75,7 @@
 int ad_makedirs(char *path)
 {
   strcpy(temp,path);
-  strcat(temp, "/yape");
+  strcat(temp, "/.yape");
   CreateDirectory(temp, NULL);
 
   return 1;
@@ -296,7 +296,7 @@
 	// Possible buffer overflow fixed.
 	strncpy(temp, path, 512);
 	if (strlen(temp) > 506) return 0;
-	strcat(temp, "/yape");
+	strcat(temp, "/.yape");
 	mkdir(temp, 0777);
 
 	return 1;
@@ -307,7 +307,7 @@
 	// Possible buffer overflow fixed.
 	strncpy(temp, tmpchr, 512);
 	if (strlen(temp) > 496) return NULL;
-	strcat( temp, "/yape/yape.conf");
+	strcat( temp, "/.yape/yape.conf");
 	return temp;
 }
 
