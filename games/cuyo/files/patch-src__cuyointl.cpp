--- src/cuyointl.cpp.orig
+++ src/cuyointl.cpp
@@ -93,7 +93,7 @@
       return convert_error(ret,s,"Character conversion not possible.");
 
     while (*inpos) {
-      size_t res = iconv(handle,&inpos,&inleft,&outpos,&outleft);
+      size_t res = iconv(handle,(const char **)&inpos,&inleft,&outpos,&outleft);
       if (res == (size_t) -1)
 	/* An error occured */
 	switch (errno) {
