--- src/slideshow.c.orig	Sun May  1 08:11:31 2005
+++ src/slideshow.c	Sun May  1 20:01:03 2005
@@ -353,8 +353,8 @@
   D_ENTER(4);
   if (action)
   {
-    D(3, ("Running action %s\n", action));
     char *sys;
+    D(3, ("Running action %s\n", action));
     sys = feh_printf(action, file);
 
     if (opt.verbose && !opt.list && !opt.customlist)
