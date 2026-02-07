--- csrd.c.orig	2017-09-13 17:02:10 UTC
+++ csrd.c
@@ -4111,7 +4111,7 @@ onintr()
 int
 main(ac, av)
 int	ac;
-uchr	**av;
+char	**av;
 {
     signal(SIGINT, onintr);
 #if defined(UNIX) && defined(RC_PATH)
