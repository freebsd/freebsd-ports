--- as/genlist.c.orig	2001-06-23 22:13:19.000000000 +0200
+++ as/genlist.c	2013-03-10 18:40:54.000000000 +0100
@@ -119,7 +119,7 @@ register char *where;
     power = 5;			/* actually 1 more than power */
     do
     {
-	for (digit = '0', power_of_10 = (powers_of_10 - 1)[power];
+	for (digit = '0', power_of_10 = powers_of_10[power - 1];
 	     num >= power_of_10; num -= power_of_10)
 	    ++digit;
 	if (power <= width)
