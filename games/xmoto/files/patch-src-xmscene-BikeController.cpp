--- src/xmscene/BikeController.cpp.orig	2008-01-06 12:56:21.000000000 +0300
+++ src/xmscene/BikeController.cpp	2008-02-05 14:49:40.000000000 +0300
@@ -77,11 +77,7 @@
     m_drive = -m_break;
   }
   else if(m_break == 0.0f){
-    if(m_throttle != 0.0f){
-      m_drive = m_throttle;
-    } else {
-      m_drive = 0.0f;
-    }
+    m_drive = m_throttle;
   }
 }
 
