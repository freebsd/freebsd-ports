
$FreeBSD$

--- html/style_y.y.orig	Sun Aug 22 17:59:06 2004
+++ html/style_y.y	Sun Aug 22 17:59:22 2004
@@ -255,7 +255,8 @@
 	 case SSTERM_HEXCOLOR:
 	 case SSTERM_URL:
 	 case SSTERM_RGB:
-	 }
+	 break;
+	}
 	 $$ = $2;
  }
  | '+' term_base	{ $$ = $2; }
