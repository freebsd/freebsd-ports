--- ./src/tnef.c.orig	2012-03-01 00:46:07.000000000 +0100
+++ ./src/tnef.c	2013-09-05 16:57:10.926068671 +0200
@@ -43,6 +43,8 @@
 
 static size_t filesize;
 
+static void free_bodies(VarLenData **bodies, int len);
+
 typedef struct
 {
     VarLenData **text_body;
@@ -386,7 +388,7 @@
     return 0;
 }
 
-void free_bodies(VarLenData **bodies, int len)
+static void free_bodies(VarLenData **bodies, int len)
 {
     while (len--)
     {
