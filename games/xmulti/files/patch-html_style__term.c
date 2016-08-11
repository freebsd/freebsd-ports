--- html/style_term.c.orig	1998-04-04 14:58:33 UTC
+++ html/style_term.c
@@ -102,6 +102,7 @@ dummy(SSTerm *t)
 	case SSTERM_HEXCOLOR:
 	case SSTERM_URL:
 	case SSTERM_RGB:
+	break;
 	}
 	return 0;
 }
