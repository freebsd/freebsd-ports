--- src/getargs.c.orig	Mon Jun 14 15:19:05 1999
+++ src/getargs.c	Mon Jan 17 03:38:56 2000
@@ -31,6 +31,7 @@
 int noparserflag = 0;
 int toknumflag = 0;
 int rawtoknumflag = 0;
+int broken_undeftoken_init;
 char *spec_name_prefix; /* for -p.  */
 char *spec_file_prefix; /* for -b. */
 extern int fixed_outfiles;/* for -y */
@@ -44,6 +45,7 @@
 
 struct option longopts[] =
 {
+  {"broken-undeftoken-init", 0, &broken_undeftoken_init, 1},
   {"debug", 0, &debugflag, 1},
   {"defines", 0, &definesflag, 1},
   {"file-prefix", 1, 0, 'b'},
