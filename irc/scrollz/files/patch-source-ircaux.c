--- source/ircaux.c.orig	Thu Oct  3 21:16:38 2002
+++ source/ircaux.c	Tue Nov 18 15:58:26 2003
@@ -869,9 +869,11 @@
 		return -10;
 #else
 	{
+#ifndef __FreeBSD__
 		if (err == EAI_ADDRFAMILY)
 			return -10;
 		else
+#endif
 			return -2;
 	}
 #endif
