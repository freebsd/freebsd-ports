--- kstars/skymap.cpp.orig	Sun Mar 31 00:10:48 2002
+++ kstars/skymap.cpp	Sun Mar 31 00:12:13 2002
@@ -45,7 +45,8 @@
 #include "addlinkdialog.h"
 
 SkyMap::SkyMap(QWidget *parent, const char *name )
- : QWidget (parent,name), downloads (0), computeSkymap (true)
+ : QWidget (parent,name), ClickedObject(0), FoundObject(0),
+       downloads (0), computeSkymap (true)
 {
 	ksw = (KStars*) kapp->mainWidget();
 
