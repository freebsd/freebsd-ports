--- klregexp.c.orig	2012-12-03 13:50:10.000000000 +0100
+++ klregexp.c	2012-12-03 13:51:40.000000000 +0100
@@ -208,6 +208,8 @@
 STATIC int strcspn();
 #endif
 
+void Klparnum_add(int, int, char *);
+
 /*
  - regcomp - compile a regular expression into internal code
  *
@@ -1302,6 +1304,7 @@
  * we maintain a p-list of parenleven, offset in program
  */
 
+void
 Klparnum_add(type, parno, ptr)
     int type;				/* OPEN or CLOSE */
     int parno;
