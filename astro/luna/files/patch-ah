--- luna.h~	1992-05-25 00:48:34.000000000 +0200
+++ luna.h	2011-12-20 19:57:27.963178999 +0100
@@ -32,7 +32,7 @@
 
 
 #if defined(ANSI)
-	extern void		main(int argc, char **argv);
+	extern int		main(int argc, char **argv);
 	extern void		drawluna(int aotmoon);
 	extern void		usage(void);
 	extern void		getoptions(int argc, char **argv,
@@ -40,7 +40,7 @@
 	extern int		getext(int year, int mon, int day);
 	extern void		printextstate(int age);
 #else
-	extern void		main();
+	extern int		main();
 	extern void		drawluna();
 	extern void		usage();
 	extern void		getoptions();
