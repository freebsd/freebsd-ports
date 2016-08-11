--- zooext.c.orig	1993-05-01 03:58:50 UTC
+++ zooext.c
@@ -163,7 +163,11 @@ if (fiz_ofs != 0L) {                /* i
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
@@ -184,7 +188,8 @@ if (null_device) {
    this_file = STDOUT;    /* standard output */
 
 while (1) {
-   frd_dir (&direntry, zoo_file);
+   if (frd_dir (&direntry, zoo_file) < 0)
+      prterror('f', bad_directory);
    if (direntry.zoo_tag != ZOO_TAG) {
       long currpos, zoolength;
 		prterror ('F', invalid_header);
