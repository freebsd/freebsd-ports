
$FreeBSD$

--- paranormal.c.orig	Sun Aug 22 17:56:22 2004
+++ paranormal.c	Sun Aug 22 17:56:36 2004
@@ -167,7 +167,7 @@
 	    case SDLK_BACKQUOTE:
 	      take_screenshot ();
 	      break;
-	    default:
+	    default: break;
 	    }
 	  break;
 	case SDL_VIDEORESIZE:
