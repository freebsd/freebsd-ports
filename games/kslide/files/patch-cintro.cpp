--- kslide/cintro.cpp.orig	Fri Jan 23 17:50:42 2004
+++ kslide/cintro.cpp	Fri Jan 23 18:23:19 2004
@@ -18,6 +18,10 @@
 #include "cintro.h"
 #include "score.h"
 
+#include <stdlib.h>
+#include <sys/types.h>
+#include <pwd.h>
+
 #include <qpainter.h>
 #include <qfont.h>
 #include <kapp.h>
@@ -86,7 +90,7 @@
   playername->hide();
   KConfig *config = kapp->config();
   config->setGroup("Player");
-  playername->setText(config->readEntry("playername",QString(cuserid(NULL))));
+  playername->setText(config->readEntry("playername",QString(getpwuid(geteuid())->pw_name)));
   playername->selectAll();
 
   setMouseTracking(true);
