--- src/level-convert.c.orig	Fri Aug 13 19:04:13 2004
+++ src/level-convert.c	Fri Aug 13 19:04:40 2004
@@ -579,6 +579,7 @@
 	case TILE_TYPE_FLOOR:
 		type_str = "TILE_TYPE_FLOOR"; break;
 	default:
+		;
 	}
 		
 	if (type_str == NULL) return;
