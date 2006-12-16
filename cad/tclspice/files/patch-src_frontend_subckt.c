--- src/frontend/subckt.c.orig	Sat Dec 16 21:03:20 2006
+++ src/frontend/subckt.c	Sat Dec 16 21:03:58 2006
@@ -79,7 +79,7 @@
 static int  numdevs(char *s);
 static bool modtranslate(struct line *deck, char *subname);
 static void devmodtranslate(struct line *deck, char *subname);
-static int inp_numnodes(char c);
+int inp_numnodes(char c);
 
 /*---------------------------------------------------------------------
  * table is used in settrans and gettrans -- it holds the netnames used 
@@ -1860,7 +1860,7 @@
  * else, but...  Note that we pretend that dependent sources and mutual
  * inductors have more nodes than they really do...
  *----------------------------------------------------------------------*/
-static int
+int
 inp_numnodes(char c)
 {
     if (isupper(c))
