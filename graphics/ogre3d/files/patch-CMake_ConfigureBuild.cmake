--- CMake/ConfigureBuild.cmake.orig	2013-04-16 03:54:30.000000000 +0200
+++ CMake/ConfigureBuild.cmake	2013-08-12 14:32:35.000000000 +0200
@@ -211,18 +211,18 @@
   else ()
     configure_file(${OGRE_TEMPLATES_DIR}/OGRE.pc.in ${OGRE_BINARY_DIR}/pkgconfig/OGRE.pc @ONLY)
   endif ()
-  install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE.pc DESTINATION ${OGRE_LIB_DIRECTORY}/pkgconfig)
+  install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE.pc DESTINATION ${OGRE_LIBDATA_DIRECTORY}/pkgconfig)
 
   # configure additional packages
 
   if (OGRE_BUILD_PLUGIN_PCZ)
     configure_file(${OGRE_TEMPLATES_DIR}/OGRE-PCZ.pc.in ${OGRE_BINARY_DIR}/pkgconfig/OGRE-PCZ.pc @ONLY)
-    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-PCZ.pc DESTINATION ${OGRE_LIB_DIRECTORY}/pkgconfig)
+    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-PCZ.pc DESTINATION ${OGRE_LIBDATA_DIRECTORY}/pkgconfig)
   endif ()
 
   if (OGRE_BUILD_COMPONENT_PAGING)
     configure_file(${OGRE_TEMPLATES_DIR}/OGRE-Paging.pc.in ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Paging.pc @ONLY)
-    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Paging.pc DESTINATION ${OGRE_LIB_DIRECTORY}/pkgconfig)
+    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Paging.pc DESTINATION ${OGRE_LIBDATA_DIRECTORY}/pkgconfig)
   endif ()
 
   if (OGRE_BUILD_COMPONENT_TERRAIN)
@@ -230,27 +230,27 @@
       set(OGRE_PAGING_ADDITIONAL_PACKAGES ", OGRE-Paging = ${OGRE_VERSION}")
     endif ()
     configure_file(${OGRE_TEMPLATES_DIR}/OGRE-Terrain.pc.in ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Terrain.pc @ONLY)
-    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Terrain.pc DESTINATION ${OGRE_LIB_DIRECTORY}/pkgconfig)
+    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Terrain.pc DESTINATION ${OGRE_LIBDATA_DIRECTORY}/pkgconfig)
   endif ()
 
   if (OGRE_BUILD_COMPONENT_RTSHADERSYSTEM)
     configure_file(${OGRE_TEMPLATES_DIR}/OGRE-RTShaderSystem.pc.in ${OGRE_BINARY_DIR}/pkgconfig/OGRE-RTShaderSystem.pc @ONLY)
-    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-RTShaderSystem.pc DESTINATION ${OGRE_LIB_DIRECTORY}/pkgconfig)
+    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-RTShaderSystem.pc DESTINATION ${OGRE_LIBDATA_DIRECTORY}/pkgconfig)
   endif ()
 
   if (OGRE_BUILD_COMPONENT_PROPERTY)
     configure_file(${OGRE_TEMPLATES_DIR}/OGRE-Property.pc.in ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Property.pc @ONLY)
-    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Property.pc DESTINATION ${OGRE_LIB_DIRECTORY}/pkgconfig)
+    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Property.pc DESTINATION ${OGRE_LIBDATA_DIRECTORY}/pkgconfig)
   endif ()
 
   if (OGRE_BUILD_COMPONENT_OVERLAY)
     configure_file(${OGRE_TEMPLATES_DIR}/OGRE-Overlay.pc.in ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Overlay.pc @ONLY)
-    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Overlay.pc DESTINATION ${OGRE_LIB_DIRECTORY}/pkgconfig)
+    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Overlay.pc DESTINATION ${OGRE_LIBDATA_DIRECTORY}/pkgconfig)
   endif ()
 
   if (OGRE_BUILD_COMPONENT_VOLUME)
     configure_file(${OGRE_TEMPLATES_DIR}/OGRE-Volume.pc.in ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Volume.pc @ONLY)
-    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Volume.pc DESTINATION ${OGRE_LIB_DIRECTORY}/pkgconfig)
+    install(FILES ${OGRE_BINARY_DIR}/pkgconfig/OGRE-Volume.pc DESTINATION ${OGRE_LIBDATA_DIRECTORY}/pkgconfig)
   endif ()
 
   if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
