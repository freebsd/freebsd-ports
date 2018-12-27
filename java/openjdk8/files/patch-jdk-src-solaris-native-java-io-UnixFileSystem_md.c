--- jdk/src/solaris/native/java/io/UnixFileSystem_md.c.orig	2018-12-12 23:07:51.229721000 +0100
+++ jdk/src/solaris/native/java/io/UnixFileSystem_md.c	2018-12-12 23:12:21.847169000 +0100
@@ -208,7 +208,8 @@
     WITH_FIELD_PLATFORM_STRING(env, file, ids.path, path) {
         struct stat64 sb;
         if (stat64(path, &sb) == 0) {
-            rv = 1000 * (jlong)sb.st_mtime;
+            rv  = (jlong)sb.st_mtim.tv_sec * 1000;
+            rv += (jlong)sb.st_mtim.tv_nsec / 1000000;
         }
     } END_PLATFORM_STRING(env, path);
     return rv;
@@ -392,8 +393,8 @@
             struct timeval tv[2];
 
             /* Preserve access time */
-            tv[0].tv_sec = sb.st_atime;
-            tv[0].tv_usec = 0;
+            tv[0].tv_sec = sb.st_atim.tv_sec;
+            tv[0].tv_usec = sb.st_atim.tv_nsec / 1000;
 
             /* Change last-modified time */
             tv[1].tv_sec = time / 1000;
