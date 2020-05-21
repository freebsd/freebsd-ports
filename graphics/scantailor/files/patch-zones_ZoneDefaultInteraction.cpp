--- zones/ZoneDefaultInteraction.cpp.orig	2020-05-21 09:38:01 UTC
+++ zones/ZoneDefaultInteraction.cpp
@@ -19,6 +19,7 @@
 #include "ZoneDefaultInteraction.h"
 #include <QMouseEvent>
 #include <QPainter>
+#include <QPainterPath>
 #include "ImageViewBase.h"
 #include "SerializableSpline.h"
 #include "ZoneInteractionContext.h"
