--- libplot/z_write.c.orig	2008-07-16 02:54:10.000000000 +0200
+++ libplot/z_write.c	2012-04-27 19:12:55.000000000 +0200
@@ -164,7 +164,7 @@
     }
 
   /* cleanup after libpng errors (error handler does a longjmp) */
-  if (setjmp (png_ptr->jmpbuf))
+  if (setjmp (png_jmpbuf(png_ptr)))
     {
       png_destroy_write_struct (&png_ptr, (png_info **)NULL);
       return -1;
@@ -444,7 +444,7 @@
 #endif
     }
 
-  longjmp (png_ptr->jmpbuf, 1);
+  longjmp (png_jmpbuf(png_ptr), 1);
 }
 
 static void 
@@ -515,7 +515,7 @@
 #endif
     }
 
-  longjmp (png_ptr->jmpbuf, 1);
+  longjmp (png_jmpbuf(png_ptr), 1);
 }
 
 static void 
