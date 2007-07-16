--- src/xterm.c.orig	Tue Oct 15 23:21:45 2002
+++ src/xterm.c	Wed Aug 31 09:18:48 2005
@@ -118,8 +118,6 @@
 #ifdef HAVE_XAW3D
 #include <X11/Xaw3d/Simple.h>
 #include <X11/Xaw3d/Scrollbar.h>
-#define ARROW_SCROLLBAR
-#include <X11/Xaw3d/ScrollbarP.h>
 #else /* !HAVE_XAW3D */
 #include <X11/Xaw/Simple.h>
 #include <X11/Xaw/Scrollbar.h>
@@ -8863,30 +8861,12 @@
 	  XawScrollbarSetThumb (widget, top, shown);
 	else
 	  {
-#ifdef HAVE_XAW3D
-	    ScrollbarWidget sb = (ScrollbarWidget) widget;
-	    int scroll_mode = 0;
-	    
-	    /* `scroll_mode' only exists with Xaw3d + ARROW_SCROLLBAR.  */
-	    if (xaw3d_arrow_scroll)
-	      {
-		/* Xaw3d stupidly ignores resize requests while dragging
-		   so we have to make it believe it's not in dragging mode.  */
-		scroll_mode = sb->scrollbar.scroll_mode;
-		if (scroll_mode == 2)
-		  sb->scrollbar.scroll_mode = 0;
-	      }
-#endif
 	    /* Try to make the scrolling a tad smoother.  */
 	    if (!xaw3d_pick_top)
 	      shown = min (shown, old_shown);
 	    
 	    XawScrollbarSetThumb (widget, top, shown);
 	    
-#ifdef HAVE_XAW3D
-	    if (xaw3d_arrow_scroll && scroll_mode == 2)
-	      sb->scrollbar.scroll_mode = scroll_mode;
-#endif
 	  }
       }
   }
