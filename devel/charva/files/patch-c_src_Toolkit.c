--- c/src/Toolkit.c.orig	Wed Dec 13 12:29:03 2006
+++ c/src/Toolkit.c	Wed Dec 13 12:35:30 2006
@@ -372,6 +372,7 @@
     if (colors_started)
 	    attr = COLOR_PAIR(colorpair_);
 
+    attron(attr);
     // If the top of the box is outside the clipping rectangle, don't bother
     // to draw the top.
     if (top_ >= top && top_ <= bottom) {
@@ -414,6 +415,7 @@
 	        my_addch_with_clip(ACS_VLINE);   // right vertical line
 	    }
     }
+    attroff(attr);
 }
 
 JNIEXPORT void JNICALL Java_charva_awt_Toolkit_blankBoxNative
