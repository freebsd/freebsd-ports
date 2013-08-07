--- CMake/ConfigureBuild.cmake.orig	2012-09-02 07:27:14.000000000 +0200
+++ CMake/ConfigureBuild.cmake	2013-06-15 16:28:56.000000000 +0200
@@ -189,18 +189,18 @@ if (UNIX)
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
@@ -208,20 +208,20 @@ if (UNIX)
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
 
-  if (CMAKE_CXX_COMPILER MATCHES ".*clang")
+  if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
     set(CMAKE_COMPILER_IS_CLANGXX 1)
   endif ()
 
