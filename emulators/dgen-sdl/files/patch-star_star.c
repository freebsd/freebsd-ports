
$FreeBSD$

--- star/star.c.orig	Sun Aug 22 22:09:09 2004
+++ star/star.c	Sun Aug 22 22:09:20 2004
@@ -1931,7 +1931,7 @@
 	case aind: case ainc: case adec:
 	case adsp: case axdp:
 		usereg();
-	default:
+	default: break;
 	}
 }
 
