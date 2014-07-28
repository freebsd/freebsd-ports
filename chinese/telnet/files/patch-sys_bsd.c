--- sys_bsd.c.orig	Sun May  4 16:03:33 2003
+++ sys_bsd.c	Sun May  4 16:04:12 2003
@@ -572,7 +572,7 @@
 	else
 		lmode &= ~LPASS8;
 #else
-	if (f & MODE_INBIN)
+	if (1)
 		tmp_tc.c_iflag &= ~ISTRIP;
 	else
 		tmp_tc.c_iflag |= ISTRIP;
