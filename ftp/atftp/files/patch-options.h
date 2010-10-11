--- options.h.orig	2001-07-07 07:35:18.000000000 +0800
+++ options.h	2010-10-11 13:11:41.000000000 +0800
@@ -39,6 +39,8 @@
 int opt_get_timeout(struct tftp_opt *options);
 int opt_get_blksize(struct tftp_opt *options);
 int opt_get_multicast(struct tftp_opt *options, char *addr, int *port, int *mc);
+int opt_equal(struct tftp_opt *opt1, struct tftp_opt *opt2);
+int opt_same_file(struct tftp_opt *opt1, struct tftp_opt *opt2);
 void opt_set_tsize(int tsize, struct tftp_opt *options);
 void opt_set_timeout(int timeout, struct tftp_opt *options);
 void opt_set_blksize(int blksize, struct tftp_opt *options);
