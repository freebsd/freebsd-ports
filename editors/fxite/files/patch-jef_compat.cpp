--- jef/compat.cpp.orig	2013-04-02 11:39:14.000000000 +0200
+++ jef/compat.cpp	2013-04-02 11:39:34.000000000 +0200
@@ -292,7 +292,7 @@
 
 
 
-static bool ClientMsg(FXTopWindow*w, const char *msg, ulong d0=0, ulong d1=0, ulong d2=0, ulong d3=0, ulong d4=0) {
+static bool ClientMsg(FXTopWindow*w, const char *msg, FXulong d0=0, FXulong d1=0, FXulong d2=0, FXulong d3=0, FXulong d4=0) {
   Display*dpy=(Display*)w->getApp()->getDisplay();
   Window root=w->getApp()->getRootWindow()->id();
   XEvent event;
