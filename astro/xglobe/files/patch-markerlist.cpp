--- markerlist.cpp.orig	1999-07-13 18:13:41 UTC
+++ markerlist.cpp
@@ -28,7 +28,7 @@
 
 #include "markerlist.h"
 #include <qfile.h>
-#include <qtextstream.h>
+#include <q3textstream.h>
 
 /* ------------------------------------------------------------------------ */
 
@@ -94,11 +94,11 @@ bool MarkerList::loadMarkerFile(const ch
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
