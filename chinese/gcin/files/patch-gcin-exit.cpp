--- gcin-exit.cpp.orig	2012-01-25 19:29:28.000000000 +0800
+++ gcin-exit.cpp	2012-01-25 19:29:38.000000000 +0800
@@ -12,7 +12,7 @@ int main()
 #if UNIX
   Display *dpy = GDK_DISPLAY();
   if (find_gcin_window(dpy)==None)
-    return;
+    return 0;
   send_gcin_message(dpy, GCIN_EXIT_MESSAGE);
 #else
   if (!find_gcin_window())
