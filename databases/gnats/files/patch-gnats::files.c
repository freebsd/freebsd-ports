--- gnats/files.c.orig	Mon Feb 12 06:36:25 2001
+++ gnats/files.c	Sat Jun 14 13:17:58 2003
@@ -271,7 +271,7 @@
   char *path = (char *) alloca (PATH_MAX);
 
   memset (array, 0, NUM_RESPONSIBLE_FIELDS * sizeof (char *));
-  sprintf (path, "%s/gnats-adm/%s", gnats_root, RESPONSIBLE_FILE);
+  snprintf (path, PATH_MAX-1, "%s/gnats-adm/%s", gnats_root, RESPONSIBLE_FILE);
   fp = fopen (path, "r");
   if (fp == NULL)
     return 0;
@@ -358,7 +358,7 @@
   int  i, nerrs = 0;
 
   memset (array, 0, NUM_CLASS_FIELDS * sizeof (char *));
-  sprintf (path, "%s/gnats-adm/%s", gnats_root, CLASSES);
+  snprintf (path, PATH_MAX-1, "%s/gnats-adm/%s", gnats_root, CLASSES);
   fp = fopen (path, "r");
 
   if (fp == NULL)
@@ -593,7 +593,7 @@
   int  i, nerrs = 0;
 
   memset (array, 0, NUM_STATE_FIELDS * sizeof (char *));
-  sprintf (path, "%s/gnats-adm/%s", gnats_root, STATES);
+  snprintf (path, PATH_MAX-1, "%s/gnats-adm/%s", gnats_root, STATES);
   fp = fopen (path, "r");
 
   if (fp == NULL)
