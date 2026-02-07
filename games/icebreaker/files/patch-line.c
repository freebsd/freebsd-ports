--- ./line.c.orig	2002-05-31 05:15:45.000000000 +0200
+++ ./line.c	2013-12-24 13:42:35.000000000 +0100
@@ -30,8 +30,9 @@
 
 Line createline(int linenum)
 {
-	Line l;
+	static Line l;
 
+	memset(&l, 0, sizeof(l));
 	switch (linenum)
 	{
 		case 1: 
