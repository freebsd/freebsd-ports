--- ./src/luaprofiler/core_profiler.c.orig	2014-05-19 04:42:14.000000000 -0400
+++ ./src/luaprofiler/core_profiler.c	2014-06-04 12:40:26.925305573 -0400
@@ -130,8 +130,7 @@
   out_filename = (_out_filename) ? (_out_filename):(OUT_FILENAME);
 
   /* the random string to build the logname is extracted */
-  /* from 'tmpnam()' (the '/tmp/' part is deleted)     */
-  randstr = tmpnam(NULL);
+  randstr = (char *)tmpfile();
   for (s = strtok(randstr, "/\\"); s; s = strtok(NULL, "/\\")) {
     randstr = s;
   }
