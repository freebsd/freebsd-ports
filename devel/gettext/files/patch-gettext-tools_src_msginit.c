--- gettext-tools/src/msginit.c.orig	Mon Nov 27 09:02:08 2006
+++ gettext-tools/src/msginit.c	Sun Dec  3 18:03:46 2006
@@ -820,3 +820,3 @@
   if (gettextlibdir == NULL || gettextlibdir[0] == '\0')
-    gettextlibdir = relocate (LIBDIR "/gettext");
+    gettextlibdir = relocate (LIBDIR "/gettext-tools");
 
@@ -887,3 +887,3 @@
   if (gettextlibdir == NULL || gettextlibdir[0] == '\0')
-    gettextlibdir = relocate (LIBDIR "/gettext");
+    gettextlibdir = relocate (LIBDIR "/gettext-tools");
 
@@ -1037,3 +1037,3 @@
 {
-  const char *prog = relocate (LIBDIR "/gettext/user-email");
+  const char *prog = relocate (LIBDIR "/gettext-tools/user-email");
   char *argv[4];
@@ -1134,3 +1134,3 @@
   argv[2] = (char *) relocate (PROJECTSDIR);
-  argv[3] = (char *) relocate (LIBDIR "/gettext");
+  argv[3] = (char *) relocate (LIBDIR "/gettext-tools");
   argv[4] = (char *) catalogname;
