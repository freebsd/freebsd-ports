--- roll.c.orig	Thu Apr  2 23:16:11 1992
+++ roll.c	Wed Jan 31 23:04:23 2001
@@ -7,7 +7,7 @@
 
 # define	reg	register
 
-# if (! defined ultrix && ! defined mips && ! defined vax)
+# if (! defined ultrix && ! defined mips && ! defined vax && ! defined __386BSD__ && ! defined __FreeBSD__)
 # define	MAXRAND	32767L
 
 roll(ndie, nsides)
