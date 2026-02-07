--- XCalendar.sed.orig	Tue Jul  4 06:59:01 1995
+++ XCalendar.sed	Sat Nov 22 03:05:34 2003
@@ -2,7 +2,9 @@
 *showGrip:		False
 *calendar*internalBorderWidth: 0
 *input:		True
-*resize: False
+*controls*resize: False
+*bcontrols*resize: False
+*daybuttons*resize: False
 *resizable: True
 *title: XCalendar v.4.0
 *dayEditor.title: Day Editor
@@ -119,9 +121,9 @@
 *daybuttons*borderWidth: 0
 
 *Scrollbar.borderWidth: 1
-*Text*scrollVertical: whenNeeded
-*scrollHorizontal: False
-*helpWindow*scrollHorizontal: True
+*Text*scrollVertical: Always
+*scrollHorizontal: Never
+*helpWindow*scrollHorizontal: Always
 *holiday*cursorPositionVisible: False
 *holiday*displayCaret: False
 *helpWindow*cursorPositionVisible: False
