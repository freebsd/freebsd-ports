--- src/goal-view.c.orig	Fri Aug 13 19:03:11 2004
+++ src/goal-view.c	Fri Aug 13 19:03:42 2004
@@ -96,6 +96,7 @@
 			case TILE_TYPE_WALL:
 			case TILE_TYPE_UNKNOWN:
 			default:
+				;
 			}
 			g_object_unref (tile);
 		}
