--- kluje/klujesystray.cpp.orig	Thu Feb 26 21:29:36 2004
+++ kluje/klujesystray.cpp	Thu Feb 26 21:34:29 2004
@@ -97,7 +97,7 @@
 {
   QUrl url = *(urls->at(id));
 
-  kdDebug(6969) << "User selected link " << url << endl;
+  kdDebug(6969) << "User selected link " << url.toString() << endl;
 
   KProcess *proc = new KProcess();
 
