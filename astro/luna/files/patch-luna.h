--- luna.h.orig	2016-07-26 13:07:24 UTC
+++ luna.h
@@ -32,7 +32,7 @@ typedef enum {
 
 
 #if defined(ANSI)
-	extern void		main(int argc, char **argv);
+	extern int		main(int argc, char **argv);
 	extern void		drawluna(int aotmoon);
 	extern void		usage(void);
 	extern void		getoptions(int argc, char **argv,
@@ -40,7 +40,7 @@ typedef enum {
 	extern int		getext(int year, int mon, int day);
 	extern void		printextstate(int age);
 #else
-	extern void		main();
+	extern int		main();
 	extern void		drawluna();
 	extern void		usage();
 	extern void		getoptions();
