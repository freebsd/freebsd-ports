--- io.c.orig	Sat Jan  8 23:36:29 2000
+++ io.c	Thu Aug  5 20:57:30 2004
@@ -894,7 +894,7 @@
 {	case 0: puts("off"); break;
 	case 1: puts("on"); break;
 	case 2: puts("on (pondering)"); break;
-	default:
+	default: ;
 }
 
 printf(" Transposition table ... ");
