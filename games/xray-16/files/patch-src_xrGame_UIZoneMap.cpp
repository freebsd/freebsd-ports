--- src/xrGame/UIZoneMap.cpp.orig	2026-09-30 22:31:46 UTC
+++ src/xrGame/UIZoneMap.cpp
@@ -143,7 +143,10 @@ void CUIZoneMap::Update(const CActor* actor)
         m_Counter_text.SetText(text_str);
     }
 
-    UpdateRadar(Device.vCameraPosition);
+    // Map locations call Actor() while updating spots, which is
+    // invalid (assertion / NULL dereference) when there is no actor.
+    if (actor)
+        UpdateRadar(Device.vCameraPosition);
     float h, p;
     Device.vCameraDirection.getHP(h, p);
     SetHeading(-h);
