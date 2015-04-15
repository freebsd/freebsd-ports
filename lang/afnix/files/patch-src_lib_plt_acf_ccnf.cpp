--- src/lib/plt/acf/ccnf.cpp.orig	2015-01-03 14:34:32.000000000 +0100
+++ src/lib/plt/acf/ccnf.cpp	2015-03-31 14:56:16.000000000 +0200
@@ -419,8 +419,6 @@ int main (int, char**) {
   fprintf (stdout, "  // pointer size type\n");
   if (platid == AFNIX_PLATFORM_DARWIN)
     fprintf (stdout, "  typedef unsigned long int  t_size;\n");
-  else if (AFNIX_FORCE_LONG == true)
-    fprintf (stdout, "  typedef unsigned long      t_size;\n");
   else if (sizeof (void*) == 8 )
     fprintf (stdout, "  typedef unsigned long      t_size;\n");
   else
