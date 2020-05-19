--- lib-src/etags.c.orig	2020-05-18 16:17:29 UTC
+++ lib-src/etags.c
@@ -4196,7 +4196,6 @@ C_entries (int c_ext, FILE *inf)
 	      objdef = omethodsign;
 	      break;
 	    }
-	  FALLTHROUGH;
 	resetfvdef:
 	case '#': case '~': case '&': case '%': case '/':
 	case '|': case '^': case '!': case '.': case '?':
