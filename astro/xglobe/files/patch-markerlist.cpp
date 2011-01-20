--- markerlist.cpp.orig	1999-07-13 11:13:41.000000000 -0700
+++ markerlist.cpp	2011-01-18 14:22:52.000000000 -0800
@@ -28,7 +28,7 @@
 
 #include "markerlist.h"
 #include <qfile.h>
-#include <qtextstream.h>
+#include <q3textstream.h>
 
 /* ------------------------------------------------------------------------ */
 
@@ -94,11 +94,11 @@
   int         pos1;
   int         pos2;
   QFile f(filename);
-  QTextStream t(&f);
+  Q3TextStream t(&f);
   QString     line;
   QColor      color;
 
-  if(!f.open(IO_ReadOnly))
+  if(!f.open(QIODevice::ReadOnly))
     return FALSE;
   
   while(!t.eof())
