--- c/src/Toolkit.c.orig	2016-06-20 12:40:44 UTC
+++ c/src/Toolkit.c
@@ -372,6 +372,7 @@ JNIEXPORT void JNICALL Java_charva_awt_T
     if (colors_started)
 	    attr = COLOR_PAIR(colorpair_);
 
+    attron(attr);
     // If the top of the box is outside the clipping rectangle, don't bother
     // to draw the top.
     if (top_ >= top && top_ <= bottom) {
@@ -414,6 +415,7 @@ JNIEXPORT void JNICALL Java_charva_awt_T
 	        my_addch_with_clip(ACS_VLINE);   // right vertical line
 	    }
     }
+    attroff(attr);
 }
 
 JNIEXPORT void JNICALL Java_charva_awt_Toolkit_blankBoxNative
