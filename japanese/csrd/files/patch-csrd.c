--- csrd.c.orig	2013-10-20 17:18:39.000000000 +0900
+++ csrd.c	2013-10-20 17:21:09.000000000 +0900
@@ -4111,7 +4111,7 @@
 int
 main(ac, av)
 int	ac;
-uchr	**av;
+char	**av;
 {
     signal(SIGINT, onintr);
 #if defined(UNIX) && defined(RC_PATH)
