--- src/res.c.orig	Fri Jan 21 02:00:34 2005
+++ src/res.c	Fri Jan 21 02:00:46 2005
@@ -50,7 +50,7 @@
 				 * don't do DNS on this ip. */
 
 #undef	DEBUG			/* because theres alot of debug code in here */
-extern void debug();
+/* extern void debug(); */
 
 struct in_addr reslocaladdr;
 
