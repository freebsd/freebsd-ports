
$FreeBSD$

--- html/frame_add.c.orig	Sun Aug 22 18:00:16 2004
+++ html/frame_add.c	Sun Aug 22 18:00:27 2004
@@ -215,7 +215,7 @@
 	case SSTERM_LENGTH_PX:
 		bfi->next_linesep = bsi->line_height.num - linesep;
 		break;
-	default:
+	default: break;
 	}
 
 	bfi->cur_x = 0;
