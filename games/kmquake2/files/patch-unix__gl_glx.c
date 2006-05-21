--- ./unix/gl_glx.c.orig	Mon Apr  3 14:40:42 2006
+++ ./unix/gl_glx.c	Sat May 20 13:51:55 2006
@@ -379,15 +379,11 @@
 					}
 					else
 					{
-						if( !event.xmotion.send_event ) {
-    						    mx += event.xmotion.x - p_mouse_x;
-						    my += event.xmotion.y - p_mouse_y;
+    					    mx += (event.xmotion.x - mwx) * 2;
+					    my += (event.xmotion.y - mwy) * 2;
 
-						    if( abs( mwx - event.xmotion.x ) > mwx / 2 || abs( mwy - event.xmotion.y ) > mwy / 2 )
+					    if (mwx || mwy)
 							dowarp = true;
-						}
-						p_mouse_x = event.xmotion.x;
-						p_mouse_y = event.xmotion.y;
 					}
 				}
 				break;
@@ -451,8 +447,6 @@
 	if (dowarp) 
 	{
 		/* move the mouse to the window center again */
-		p_mouse_x = mwx;
-		p_mouse_y = mwy;
 		XWarpPointer (dpy, None, win, 0, 0, 0, 0, mwx, mwy);
 	}
 }
