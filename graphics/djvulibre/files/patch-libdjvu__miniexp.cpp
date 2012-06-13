--- libdjvu/miniexp.cpp.orig	2012-05-07 22:56:53.000000000 -0400
+++ libdjvu/miniexp.cpp	2012-06-12 07:23:54.000000000 -0400
@@ -1008,7 +1008,7 @@
   if (io == &miniexp_io && !CompatCounter::count)
     return (*minilisp_getc)(); /* compatibility hack */
   FILE *f = (io->data[0]) ? (FILE*)(io->data[0]) : stdin;
-  return ::getc(f);
+  return getc(f);
 }
 
 static int 
