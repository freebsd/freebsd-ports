--- conserver/group.c.orig	2008-07-03 08:06:56.000000000 +0900
+++ conserver/group.c	2008-07-03 08:08:28.000000000 +0900
@@ -3839,12 +3839,10 @@
 					      "failed]\r\n", -1);
 				    continue;
 				}
-				if (TAB3 == (TABDLY & sbuf.c_oflag)) {
-				    sbuf.c_oflag &= ~TABDLY;
-				    sbuf.c_oflag |= TAB0;
+				if (sbuf.c_oflag & OXTABS) {
+				    sbuf.c_oflag &= ~OXTABS;
 				} else {
-				    sbuf.c_oflag &= ~TABDLY;
-				    sbuf.c_oflag |= TAB3;
+				    sbuf.c_oflag |= OXTABS;
 				}
 				if (-1 ==
 				    tcsetattr(FileFDNum
