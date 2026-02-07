--- graphics/i_x11_fast.c.orig	2003-12-08 22:48:58 UTC
+++ graphics/i_x11_fast.c
@@ -201,13 +201,9 @@ int xlatekey(void)
       /* This is an ugly PC-ism. Better switch to XLookupKeysym() ? */
       case XK_KP_Insert:       rc = '0';       break;
       case XK_KP_End:          rc = '1';       break;
-      case XK_KP_Down:         rc = '2';       break;
       case XK_KP_Page_Down:    rc = '3';       break;
-      case XK_KP_Left:         rc = '4';       break;
       case XK_KP_Begin:                rc = '5';       break;
-      case XK_KP_Right:                rc = '6';       break;
       case XK_KP_Home:         rc = '7';       break;
-      case XK_KP_Up:           rc = '8';       break;
       case XK_KP_Page_Up:      rc = '9';       break;
 	
       case XK_Shift_L:
