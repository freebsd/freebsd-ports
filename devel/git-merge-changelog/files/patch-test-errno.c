--- gltests/test-errno.c.orig	2013-08-05 11:25:41.000000000 +0900
+++ gltests/test-errno.c	2013-09-18 16:47:59.374921027 +0900
@@ -98,8 +98,8 @@
 int e116 = ESTALE;
 int e122 = EDQUOT;
 int e125 = ECANCELED;
-int e130 = EOWNERDEAD;
-int e131 = ENOTRECOVERABLE;
+/* int e130 = EOWNERDEAD; */
+/* int e131 = ENOTRECOVERABLE; */
 
 /* Don't verify that these errno values are all different, except for possibly
    EWOULDBLOCK == EAGAIN.  Even Linux/x86 does not pass this check: it has
