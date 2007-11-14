--- ircd/whowas.c.orig	2007-11-14 03:10:38.000000000 +0600
+++ ircd/whowas.c	2007-11-14 03:10:44.000000000 +0600
@@ -331,7 +331,7 @@
 		if (lk_index)
 			memcpy((aLock *)nlp,(aLock *)lp,
 					sizeof(*lp) * lk_index);
-		MyFree((void *)locked);
+		MyFree(locked);
 		locked = nlp;
 		return (1);
 	}
