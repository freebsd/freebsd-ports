--- src/c++/libhdfs/hdfs.c.orig	2011-08-07 16:38:59.000000000 +0200
+++ src/c++/libhdfs/hdfs.c	2011-08-07 16:39:18.000000000 +0200
@@ -252,7 +252,7 @@
       cURI = malloc(strlen(host)+16);
       sprintf(cURI, "hdfs://%s:%d", host, (int)(port));
       if (cURI == NULL) {
-        fprintf (stderr, "Couldn't allocate an object of size %d",
+        fprintf (stderr, "Couldn't allocate an object of size %llu",
                  strlen(host) + 16);
         errno = EINTERNAL;			
         goto done;	
