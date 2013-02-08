--- cnv/cubitorle.c.orig	1992-01-29 02:51:35.000000000 +0900
+++ cnv/cubitorle.c	2012-10-15 22:27:30.000000000 +0900
@@ -31,7 +31,7 @@
 
 void read_cubi_hdr(), read_cubi_row(), read_cubi_chan(), bit_read();
 
-void
+int
 main(argc, argv)
 int	argc;
 char	*argv[];
