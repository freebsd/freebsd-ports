--- gettext-tools/src/msginit.c.orig	Fri May 20 00:14:54 2005
+++ gettext-tools/src/msginit.c	Fri May 20 00:15:16 2005
@@ -950,7 +950,7 @@
 
   gettextlibdir = getenv ("GETTEXTLIBDIR");
   if (gettextlibdir == NULL || gettextlibdir[0] == '\0')
-    gettextlibdir = relocate (LIBDIR "/gettext");
+    gettextlibdir = relocate (LIBDIR "/gettext-tools");
 
   prog = concatenated_pathname (gettextlibdir, "project-id", NULL);
 
@@ -1016,7 +1016,7 @@
 
   gettextlibdir = getenv ("GETTEXTLIBDIR");
   if (gettextlibdir == NULL || gettextlibdir[0] == '\0')
-    gettextlibdir = relocate (LIBDIR "/gettext");
+    gettextlibdir = relocate (LIBDIR "/gettext-tools");
 
   prog = concatenated_pathname (gettextlibdir, "project-id", NULL);
 
@@ -1165,7 +1165,7 @@
 static const char *
 get_user_email ()
 {
-  const char *prog = relocate (LIBDIR "/gettext/user-email");
+  const char *prog = relocate (LIBDIR "/gettext-tools/user-email");
   char *argv[4];
   pid_t child;
   int fd[1];
@@ -1261,7 +1261,7 @@
   argv[0] = "/bin/sh";
   argv[1] = (char *) prog;
   argv[2] = (char *) relocate (PROJECTSDIR);
-  argv[3] = (char *) relocate (LIBDIR "/gettext");
+  argv[3] = (char *) relocate (LIBDIR "/gettext-tools");
   argv[4] = (char *) catalogname;
   argv[5] = (char *) language;
   argv[6] = NULL;
