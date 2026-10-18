--- ui/zenoedit/viewport/cameracontrol.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/viewport/cameracontrol.cpp
@@ -105,7 +105,7 @@ void CameraControl::fakeMousePressEvent(
     if (event->button() == Qt::MiddleButton) {
         middle_button_pressed = true;
         if (zeno::getSession().userData().get2<bool>("viewport-depth-aware-navigation", true)) {
-            m_hit_posWS = scene->renderMan->getEngine()->getClickedPos(event->x(), event->y());
+            m_hit_posWS = scene->renderMan->getEngine()->getClickedPos(event->position().x(), event->position().y());
             if (m_hit_posWS.has_value()) {
                 scene->camera->setPivot(m_hit_posWS.value());
             }
@@ -119,7 +119,7 @@ void CameraControl::fakeMousePressEvent(
     settings.getViewShortCut(ShortCut_RotatingView, button);
     bool bTransform = false;
     auto front = scene->camera->get_lodfront();
-    auto dir = screenPosToRayWS(event->x() / res().x(), event->y() / res().y());
+    auto dir = screenPosToRayWS(event->position().x() / res().x(), event->position().y() / res().y());
     if (m_transformer)
     {
         if (event->buttons() & Qt::LeftButton && !scene->selected.empty() && m_transformer->isTransformMode() &&
@@ -249,7 +249,7 @@ void CameraControl::fakeMouseMoveEvent(Q
         bTransform = m_transformer->isTransforming();
         // check if hover a handler
         auto front = scene->camera->get_lodfront();
-        auto dir = screenPosToRayWS(event->x() / res().x(), event->y() / res().y());
+        auto dir = screenPosToRayWS(event->position().x() / res().x(), event->position().y() / res().y());
         if (!scene->selected.empty() && !(event->buttons() & Qt::LeftButton)) {
             m_transformer->hoveredAnyHandler(getPos(), dir, front);
         }
@@ -271,7 +271,7 @@ void CameraControl::fakeMouseMoveEvent(Q
     else if (!bTransform && ctrl_pressed && (event->buttons() & Qt::MiddleButton)) {
         // rot roll
         float step = 1.0f;
-        float ratio = QApplication::desktop()->devicePixelRatio();
+        float ratio = qApp->devicePixelRatio();
         float dy = ypos - m_lastMidButtonPos.y();
         dy *= ratio / m_res[1] * step;
         {
@@ -282,7 +282,7 @@ void CameraControl::fakeMouseMoveEvent(Q
         m_lastMidButtonPos = QPointF(xpos, ypos);
     }
     else if (!bTransform && (event->buttons() & (rotateButton | moveButton))) {
-        float ratio = QApplication::desktop()->devicePixelRatio();
+        float ratio = qApp->devicePixelRatio();
         float dx = xpos - m_lastMidButtonPos.x(), dy = ypos - m_lastMidButtonPos.y();
         dx *= ratio / m_res[0];
         dy *= ratio / m_res[1];
@@ -291,7 +291,7 @@ void CameraControl::fakeMouseMoveEvent(Q
         if ((moveKey == modifiers) && (event->buttons() & moveButton)) {
             // translate
             if (m_hit_posWS.has_value()) {
-                auto ray = screenPosToRayWS(event->x() / res().x(), event->y() / res().y());
+                auto ray = screenPosToRayWS(event->position().x() / res().x(), event->position().y() / res().y());
                 auto new_pos = intersectRayPlane(m_hit_posWS.value(), ray * (-1.0f), getPos(), getViewDir());
                 if (new_pos.has_value()) {
                     auto diff = new_pos.value() - getPos();
@@ -432,14 +432,14 @@ void CameraControl::fakeWheelEvent(QWhee
             if (zeno::getSession().userData().get2<bool>("viewport-depth-aware-navigation", true)) {
                 auto session = m_zenovis->getSession();
                 auto scene = session->get_scene();
-                auto hit_posWS = scene->renderMan->getEngine()->getClickedPos(event->x(), event->y());
+                auto hit_posWS = scene->renderMan->getEngine()->getClickedPos(event->position().x(), event->position().y());
                 if (hit_posWS.has_value()) {
                     auto pivot = hit_posWS.value();
                     auto new_pos = (pos - pivot) * scale + pivot;
                     setPos(new_pos);
                 }
                 else {
-                    auto posOnFloorWS = screenHitOnFloorWS(event->x() / res().x(), event->y() / res().y());
+                    auto posOnFloorWS = screenHitOnFloorWS(event->position().x() / res().x(), event->position().y() / res().y());
                     auto pivot = posOnFloorWS;
                     if (dot((pivot - pos), getViewDir()) > 0) {
                         auto translate = (pivot - pos) * (1 - scale);
@@ -450,7 +450,7 @@ void CameraControl::fakeWheelEvent(QWhee
                         setPos(new_pos);
                     }
                     else {
-                        auto translate = screenPosToRayWS(event->x() / res().x(), event->y() / res().y()) * getPos().y * (1 - scale);
+                        auto translate = screenPosToRayWS(event->position().x() / res().x(), event->position().y() / res().y()) * getPos().y * (1 - scale);
                         if (getPos().y < 0) {
                             translate *= -1;
                         }
