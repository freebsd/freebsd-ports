--- src/readpng.c.orig	2004-10-31 16:00:23.000000000 +0100
+++ src/readpng.c	2012-05-06 16:05:53.000000000 +0200
@@ -63,7 +63,7 @@
 use_errmsg=1;
 
 /* cleanup is done after jump back, so just do that now... */
-longjmp(png_ptr->jmpbuf,1);
+longjmp( png_jmpbuf(png_ptr),1);
 }
 
 
@@ -132,7 +132,7 @@
   return(_PICERR_NOMEM);
   }
 
-if(setjmp(png_ptr->jmpbuf))
+if(setjmp(png_jmpbuf(png_ptr)))
   {
   /* if we get here, there was an error. */
   /* don't use local variables here, they may have been blasted */
