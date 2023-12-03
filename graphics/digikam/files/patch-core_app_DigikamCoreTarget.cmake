--- core/app/DigikamCoreTarget.cmake.orig	2023-11-29 09:52:21 UTC
+++ core/app/DigikamCoreTarget.cmake
@@ -81,7 +81,7 @@ endif()
 
 endif()
 
-if(KF${QT_VERSION_MAJOR}AkonadiContact_FOUND)
+if(KPim${QT_VERSION_MAJOR}AkonadiContact_FOUND)
 
     set(DIGIKAMCORE_OBJECTS
         ${DIGIKAMCORE_OBJECTS}
@@ -395,11 +395,11 @@ endif()
 
 endif()
 
-if(KF${QT_VERSION_MAJOR}AkonadiContact_FOUND)
+if(KPim${QT_VERSION_MAJOR}AkonadiContact_FOUND)
 
     target_link_libraries(digikamcore
                           PRIVATE
-                          KF${QT_VERSION_MAJOR}::AkonadiContact
+                          KPim${QT_VERSION_MAJOR}::AkonadiContact
     )
 
 endif()
