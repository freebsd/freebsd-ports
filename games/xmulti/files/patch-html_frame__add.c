--- html/frame_add.c.orig	1997-12-26 02:41:29 UTC
+++ html/frame_add.c
@@ -215,7 +215,7 @@ frame_add_lf(Frame *f, int mode)
 	case SSTERM_LENGTH_PX:
 		bfi->next_linesep = bsi->line_height.num - linesep;
 		break;
-	default:
+	default: break;
 	}
 
 	bfi->cur_x = 0;
