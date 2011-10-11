Index: magick/string.c
===================================================================
--- magick/string.c	(revision 5596)
+++ magick/string.c	(revision 5597)
@@ -734,6 +734,8 @@
   register size_t
     n;
 
+  if (source == (const char *) NULL)
+    return(0);
   p=source;
   q=destination;
   for (n=length; n > 4; n-=4)
