--- lib/TWindow.cc.orig	2008-07-27 18:50:18.000000000 +0200
+++ lib/TWindow.cc	2008-07-27 18:50:37.000000000 +0200
@@ -153,7 +153,7 @@
 		/*
 		 * Some non-portable code changed.  See `TProgram.cc'.
 		 */
-		(int)event.message.infoPtr == number &&
+		(intptr_t)event.message.infoPtr == number &&
              (options & ofSelectable) != 0
            )
             {
