--- libplot/z_write.c.orig	2008-07-16 00:54:10 UTC
+++ libplot/z_write.c
@@ -164,7 +164,7 @@ _pl_z_maybe_output_image (S___(Plotter *_plotter))
     }
 
   /* cleanup after libpng errors (error handler does a longjmp) */
-  if (setjmp (png_ptr->jmpbuf))
+  if (setjmp (png_jmpbuf(png_ptr)))
     {
       png_destroy_write_struct (&png_ptr, (png_info **)NULL);
       return -1;
@@ -444,7 +444,7 @@ _our_error_fn_stdio (png_struct *png_ptr, const char *
 #endif
     }
 
-  longjmp (png_ptr->jmpbuf, 1);
+  longjmp (png_jmpbuf(png_ptr), 1);
 }
 
 static void 
@@ -515,7 +515,7 @@ _our_error_fn_stream (png_struct *png_ptr, const char 
 #endif
     }
 
-  longjmp (png_ptr->jmpbuf, 1);
+  longjmp (png_jmpbuf(png_ptr), 1);
 }
 
 static void 
