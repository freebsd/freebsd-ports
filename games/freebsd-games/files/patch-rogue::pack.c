$FreeBSD$

--- rogue/pack.c	30 Nov 1999 03:49:25 -0000	1.8
+++ rogue/pack.c	21 Aug 2003 20:07:28 -0000
@@ -342,7 +342,7 @@
 	char desc[DCOLS];
 
 	if (rogue.armor) {
-		message("your already wearing some", 0);
+		message("you're already wearing some", 0);
 		return;
 	}
 	ch = pack_letter("wear what?", ARMOR);
