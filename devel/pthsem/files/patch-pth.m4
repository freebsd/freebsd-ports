--- ./pth.m4.orig	2008-07-09 23:22:42.000000000 +0200
+++ ./pth.m4	2014-04-22 19:09:18.070826022 +0200
@@ -296,7 +296,7 @@
             exit(0);
         ])
 	m4_define(_code3, [dnl
-	int main(int argc, char *argv[])
+	int main(int argc, char **argv)
 	{
 	])
 	m4_define(_code4, [dnl
