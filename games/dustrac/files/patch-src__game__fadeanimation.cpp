--- ./src/game/fadeanimation.cpp.orig	2014-03-09 12:40:35.000000000 +0000
+++ ./src/game/fadeanimation.cpp	2014-04-05 13:27:41.052483713 +0000
@@ -81,7 +81,7 @@
 #ifdef Q_OS_ANDROID
         emit fadeValueChanged(fmin(m_fadeValue, 1.0));
 #else
-        emit fadeValueChanged(std::fmin(m_fadeValue, 1.0));
+        emit fadeValueChanged(fmin(m_fadeValue, 1.0));
 #endif
     }
     else if (!m_fadeIn && m_fadeValue > 0.0)
@@ -90,7 +90,7 @@
 #ifdef Q_OS_ANDROID
         emit fadeValueChanged(fmax(m_fadeValue, 0.0));
 #else
-        emit fadeValueChanged(std::fmax(m_fadeValue, 0.0));
+        emit fadeValueChanged(fmax(m_fadeValue, 0.0));
 #endif
     }
     else if (m_postDelayMSec)
