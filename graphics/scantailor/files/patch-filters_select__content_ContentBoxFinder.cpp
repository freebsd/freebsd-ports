--- filters/select_content/ContentBoxFinder.cpp.orig	2020-05-21 09:40:03 UTC
+++ filters/select_content/ContentBoxFinder.cpp
@@ -19,6 +19,7 @@
 #include "ContentBoxFinder.h"
 #include <QDebug>
 #include <QPainter>
+#include <QPainterPath>
 #include <cmath>
 #include <queue>
 #include "DebugImages.h"
@@ -1353,4 +1354,4 @@ const SEDM& ContentBoxFinder::Garbage::sedm() {
 
   return m_sedm;
 }
-}  // namespace select_content
\ No newline at end of file
+}  // namespace select_content
