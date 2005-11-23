
$FreeBSD$

--- bin/kawapath.c.orig
+++ bin/kawapath.c
@@ -15,8 +15,8 @@
   const char *path = getenv("KAWALIB");
   if (path == NULL)
     {
-      path = kawalib;
       const char *rp = progname == NULL ? NULL : strrchr(progname, '/');
+      path = kawalib;
       if (rp != NULL)
 	{
 	  /* If kawa is executed "in place" as $builddir/bin/kawa
