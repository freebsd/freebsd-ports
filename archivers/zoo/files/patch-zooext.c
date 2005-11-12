--- zooext.c~	Sat May  1 05:58:50 1993
+++ zooext.c	Sat Nov 12 14:04:17 2005
@@ -184,7 +184,8 @@
    this_file = STDOUT;    /* standard output */
 
 while (1) {
-   frd_dir (&direntry, zoo_file);
+   if (frd_dir (&direntry, zoo_file) < 0)
+      prterror('f', bad_directory);
    if (direntry.zoo_tag != ZOO_TAG) {
       long currpos, zoolength;
 		prterror ('F', invalid_header);
