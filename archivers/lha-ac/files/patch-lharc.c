--- src/lharc.c.orig	Sun Sep 21 15:58:52 2003
+++ src/lharc.c	Thu Sep 23 07:22:19 2004
@@ -994,9 +994,10 @@
     struct stat     tmp_stbuf, arc_stbuf, fil_stbuf;
     int exist_tmp = 1, exist_arc = 1;
 
-    strcpy(newname, name);
+    strncpy(newname, name, sizeof(newname));
+    newname[sizeof(newname)-1] = 0;
     len = strlen(name);
-    if (len > 0 && newname[len - 1] != '/') {
+    if (len > 0 && newname[len - 1] != '/' && len < (sizeof(newname)-1)) {
         newname[len++] = '/';
         newname[len] = 0;
     }
@@ -1014,12 +1015,16 @@
 
     while ((dp = readdir(dirp)) != NULL) {
         n = NAMLEN(dp);
+        if (len >= (sizeof(newname)-1)
+            || (len+n) >= (sizeof(newname)-1)
+            || n  <= 0
+            || (len+n) <= 0)
+            break;
 
         /* exclude '.' and '..' */
         if (strncmp(dp->d_name, ".", n) == 0
             || strncmp(dp->d_name, "..", n) == 0)
             continue;
-
         /* exclude exclude_files supplied by user */
         for (i = 0; exclude_files && exclude_files[i]; i++) {
             if (fnmatch(exclude_files[i], dp->d_name,
@@ -1092,10 +1097,16 @@
 #else
     char           *p, *s;
 
-    strcpy(temporary_name, archive_name);
+    strncpy(temporary_name, archive_name, sizeof(temporary_name));
+    temporary_name[sizeof(temporary_name)-1] = 0;
     for (p = temporary_name, s = (char *) 0; *p; p++)
         if (*p == '/')
             s = p;
+  
+    if( sizeof(temporary_name) - ((size_t) (s-temporary_name)) - 1
+        <= strlen("lhXXXXXX"))
+        exit(-1);
+
     strcpy((s ? s + 1 : temporary_name), "lhXXXXXX");
 #endif
 #ifdef HAVE_MKSTEMP
