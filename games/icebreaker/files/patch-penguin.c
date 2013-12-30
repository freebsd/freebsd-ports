--- ./penguin.c.orig	2002-05-31 05:15:46.000000000 +0200
+++ ./penguin.c	2013-12-24 13:42:35.000000000 +0100
@@ -40,8 +40,9 @@
 
 Penguin createpenguinxy(int x, int y)
 {
-	Penguin p;
+	static Penguin p;
 
+	memset(&p, 0, sizeof(p));
 	switch (random() % 4)
 	{
 		case 0:
