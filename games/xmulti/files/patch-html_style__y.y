--- html/style_y.y.orig	1998-04-04 14:58:33 UTC
+++ html/style_y.y
@@ -255,7 +255,8 @@ term
 	 case SSTERM_HEXCOLOR:
 	 case SSTERM_URL:
 	 case SSTERM_RGB:
-	 }
+	 break;
+	}
 	 $$ = $2;
  }
  | '+' term_base	{ $$ = $2; }
