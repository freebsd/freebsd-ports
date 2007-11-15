--- olt.c.orig	2007-11-16 03:09:17.000000000 +0600
+++ olt.c	2007-11-16 03:12:11.000000000 +0600
@@ -85,7 +85,7 @@
 				case VXFS_OLTSB:
 					break;
 				}
-			(int) ent += ent->oltcommon.size;
+			ent = (char *) ent + ent->oltcommon.size;
 		}
 
 	if (vxdebug)
