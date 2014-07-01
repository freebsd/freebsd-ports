--- help.c.orig	2014-03-20 18:05:17.000000000 -0700
+++ help.c	2014-06-27 21:52:48.000000000 -0700
@@ -584,7 +584,10 @@
 char s[512];
 char chr;
 int i,j,k;
-msg_file=fopen(msg_filename, "r");
+char *fn;
+asprintf(&fn, "%s/%s", "%%DATADIR%%", msg_filename);
+msg_file=fopen(fn, "r");
+free(fn);
 if(msg_file == NULL)
   {
   sprintf(s,"Could not find %s",msg_filename);
