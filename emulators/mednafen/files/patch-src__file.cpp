--- src/file.cpp.orig	2009-05-15 06:12:55.000000000 +0400
+++ src/file.cpp	2013-06-07 18:52:21.000000000 +0400
@@ -229,7 +229,7 @@
    goto doret;
   }
 
-  while((howmany = gzread(tz, tmp->data + cur_size, cur_alloced - cur_size)) > 0)
+  while((howmany = gzread((gzFile)tz, tmp->data + cur_size, cur_alloced - cur_size)) > 0)
   {
    cur_size += howmany;
    cur_alloced <<= 1;
@@ -282,7 +282,7 @@
  }
  else if(type == MDFN_FILETYPE_GZIP)
  {
-  gzclose(tz);
+  gzclose((gzFile)tz);
  }
  else if(type == MDFN_FILETYPE_ZIP)
  {
@@ -444,7 +444,7 @@
 
    if(!(fceufp = MakeMemWrap(t, 1)))
    {
-    gzclose(t);
+    gzclose((gzFile)t);
     return(0);
    }
 
