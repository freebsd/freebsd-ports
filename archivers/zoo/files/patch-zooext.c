--- ./zooext.c.orig	1993-05-01 05:58:50.000000000 +0200
+++ ./zooext.c	2011-12-22 14:03:37.000000000 +0100
@@ -163,7 +163,11 @@
 } else {
    /* read header */
    frd_zooh (&zoo_header, zoo_file);
+#ifdef __LP64__
+   if ((int)(zoo_header.zoo_start + zoo_header.zoo_minus) != 0) {
+#else
    if ((zoo_header.zoo_start + zoo_header.zoo_minus) != 0L) {
+#endif
       prterror ('w', failed_consistency);
       bad_header++;
 		exit_status = 1;
@@ -184,7 +188,8 @@
    this_file = STDOUT;    /* standard output */
 
 while (1) {
-   frd_dir (&direntry, zoo_file);
+   if (frd_dir (&direntry, zoo_file) < 0)
+      prterror('f', bad_directory);
    if (direntry.zoo_tag != ZOO_TAG) {
       long currpos, zoolength;
 		prterror ('F', invalid_header);
