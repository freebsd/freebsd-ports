
$FreeBSD$

--- html/style_term.c.orig	Sun Aug 22 17:59:45 2004
+++ html/style_term.c	Sun Aug 22 17:59:56 2004
@@ -102,6 +102,7 @@
 	case SSTERM_HEXCOLOR:
 	case SSTERM_URL:
 	case SSTERM_RGB:
+	break;
 	}
 	return 0;
 }
