Index: source/ircaux.c
diff -u source/ircaux.c.orig source/ircaux.c
--- source/ircaux.c.orig	Sun Jan 13 09:41:25 2002
+++ source/ircaux.c	Thu Oct 30 00:57:46 2003
@@ -852,9 +852,11 @@
 		return -10;
 #else
 	{
+#ifdef EAI_ADDRFAMILY
 		if (err == EAI_ADDRFAMILY)
 			return -10;
 		else
+#endif
 			return -2;
 	}
 #endif
