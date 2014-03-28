--- ./olt.c.orig	1999-12-02 15:19:27.000000000 +0100
+++ ./olt.c	2014-03-14 13:54:55.821662410 +0100
@@ -85,7 +85,7 @@
 				case VXFS_OLTSB:
 					break;
 				}
-			(int) ent += ent->oltcommon.size;
+			ent = (char *) ent + ent->oltcommon.size;
 		}
 
 	if (vxdebug)
