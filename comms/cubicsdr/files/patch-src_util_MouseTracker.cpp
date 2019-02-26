--- src/util/MouseTracker.cpp.orig	2019-02-25 12:54:38 UTC
+++ src/util/MouseTracker.cpp
@@ -30,7 +30,7 @@ void MouseTracker::OnMouseMoved(wxMouseEvent& event) {
 
     if (isMouseDown || isMouseRightDown) {
 #ifndef __APPLE__
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
         if (horizDragLock && vertDragLock) {
             target->WarpPointer(originMouseX * ClientSize.x, (1.0 - originMouseY) * ClientSize.y);
             mouseX = originMouseX;
