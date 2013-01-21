--- cnv/rastorle.c.orig	1992-04-30 22:58:02.000000000 +0900
+++ cnv/rastorle.c	2012-10-16 00:16:45.000000000 +0900
@@ -72,7 +72,7 @@
     		        green[CMAPSIZE],	/* Green ditto */
 	    		blue[CMAPSIZE];	/* see a pattern? */
 
-void
+int
 main(argc, argv)
 int argc;
 char *argv[];
