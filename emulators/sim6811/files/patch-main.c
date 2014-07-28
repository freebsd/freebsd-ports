--- main.c.orig	Tue Mar 22 17:16:59 1994
+++ main.c	Tue Aug 10 21:28:07 2004
@@ -70,13 +70,6 @@
 #include <ctype.h>
 #include "sim.h"
 
-extern int printf();
-extern int fprintf();
-extern int fclose();
-extern int fscanf();
-extern int sscanf();
-extern int fflush();
-
 /* how to handle all other op codes */
 void bad_op(m6811 state)
 {
@@ -323,19 +316,7 @@
 
     case '?':			/* help */
 	(void) fgets(line, sizeof(line), stdin);
-	printf(
-	       "
-
- (empty line)     step once
-s [n]		  step n times
-b [add [n]]	  set break at add which will survive n hits
-g [add [n]]	  set pc to add, step n times
-l [add [n]]	  list n lines of disassembly starting from pc
-m add n		  set specified memory location to n
-R		  Reset memory, regs and reload code
-t [add [n]]	  set temporary break at add which will survive n hits
-q or EOF	  exit simulator
-?		  print this list\n\n");
+	printf("\n\n (empty line)     step once\ns [n]		  step n times\nb [add [n]]	  set break at add which will survive n hits\ng [add [n]]	  set pc to add, step n times\nl [add [n]]	  list n lines of disassembly starting from pc\nm add n		  set specified memory location to n\nR		  Reset memory, regs and reload code\nt [add [n]]	  set temporary break at add which will survive n hits\nq or EOF	  exit simulator\n?		  print this list\n\n");
 	printf("hit return to continue");
 	fflush(stdout);
 	fgets(line, sizeof(line), stdin);
