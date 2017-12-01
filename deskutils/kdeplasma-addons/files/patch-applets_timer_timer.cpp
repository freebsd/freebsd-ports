Fix ambiguous call on armv6/armv7.

--- applets/timer/timer.cpp.orig	2017-01-12 05:36:14 UTC
+++ applets/timer/timer.cpp
@@ -498,7 +498,7 @@ void Timer::toggleTimerVisible()
         m_blinkAnim = animGroup;
     }
 
-    m_blinkAnim->setDirection(qFuzzyCompare(m_hoursDigit[0]->opacity(), 1.0) ?
+    m_blinkAnim->setDirection(qFuzzyCompare(m_hoursDigit[0]->opacity(), qreal(1.0)) ?
                               QAbstractAnimation::Forward : QAbstractAnimation::Backward);
     m_blinkAnim->start();
 }
