--- apps/openmw/mwworld/weather.cpp.orig	2015-11-22 18:54:17 UTC
+++ apps/openmw/mwworld/weather.cpp
@@ -95,9 +95,10 @@ T TimeOfDayInterpolator<T>::getValue(con
 }
 
 
-
-template class TimeOfDayInterpolator<float>;
-template class TimeOfDayInterpolator<osg::Vec4f>;
+namespace MWWorld {
+    template class TimeOfDayInterpolator<float>;
+    template class TimeOfDayInterpolator<osg::Vec4f>;
+};
 
 Weather::Weather(const std::string& name,
                  const MWWorld::Fallback& fallback,
@@ -1133,4 +1134,3 @@ inline void WeatherManager::calculateTra
         mResult.mAmbientLoopSoundID = other.mAmbientLoopSoundID;
     }
 }
-
