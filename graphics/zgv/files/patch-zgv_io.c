--- src/zgv_io.c.orig
+++ src/zgv_io.c
@@ -645,7 +645,7 @@
         case SDLK_INSERT:	return(RK_INSERT);
         case SDLK_DELETE:	return(RK_DELETE);
         case SDLK_RETURN:	return(RK_ENTER);
-        default:
+        default: ;
           /* stop complaints */
         }
 
