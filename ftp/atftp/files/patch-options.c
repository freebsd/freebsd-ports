--- options.c.orig	2003-04-25 08:16:18.000000000 +0800
+++ options.c	2010-10-11 10:23:20.000000000 +0800
@@ -273,6 +273,12 @@
      return ERR;
 }
 
+int opt_equal(struct tftp_opt *opt1, struct tftp_opt *opt2)
+{
+     return ((strncmp(opt1->option, opt2->option, OPT_SIZE) == 0) &&
+             (strncmp(opt1->value, opt2->value, OPT_SIZE) == 0));
+} 
+
 void opt_set_tsize(int tsize, struct tftp_opt *options)
 {
      snprintf(options[OPT_TSIZE].value, VAL_SIZE, "%d", tsize);
