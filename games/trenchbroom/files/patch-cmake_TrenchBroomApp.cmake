--- cmake/TrenchBroomApp.cmake.orig	2016-03-09 20:19:17 UTC
+++ cmake/TrenchBroomApp.cmake
@@ -1,4 +1,4 @@
-INCLUDE(cmake/GenerateHelp.cmake)
+#INCLUDE(cmake/GenerateHelp.cmake)
 
 SET(APP_DIR "${CMAKE_SOURCE_DIR}/app")
 SET(APP_SOURCE_DIR "${APP_DIR}/src")
@@ -84,8 +84,8 @@ ENDIF()
 
 ADD_EXECUTABLE(TrenchBroom WIN32 MACOSX_BUNDLE ${APP_SOURCE} $<TARGET_OBJECTS:common>)
 
-TARGET_LINK_LIBRARIES(TrenchBroom glew ${wxWidgets_LIBRARIES} ${FREETYPE_LIBRARIES} ${FREEIMAGE_LIBRARIES})
-SET_TARGET_PROPERTIES(TrenchBroom PROPERTIES COMPILE_DEFINITIONS "GLEW_STATIC")
+TARGET_LINK_LIBRARIES(TrenchBroom GLEW freetype ${wxWidgets_LIBRARIES} ${FREETYPE_LIBRARIES} ${FREEIMAGE_LIBRARIES})
+#SET_TARGET_PROPERTIES(TrenchBroom PROPERTIES COMPILE_DEFINITIONS "GLEW_STATIC")
 
 GET_APP_VERSION("${APP_DIR}" CPACK_PACKAGE_VERSION_MAJOR CPACK_PACKAGE_VERSION_MINOR CPACK_PACKAGE_VERSION_PATCH)
 GET_BUILD_ID("${GIT_EXECUTABLE}" "${CMAKE_SOURCE_DIR}" APP_BUILD_ID)
@@ -102,7 +102,7 @@ ADD_CUSTOM_TARGET(GenerateVersion 
     ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_BINARY_DIR}/GenerateVersion.cmake")
 ADD_DEPENDENCIES(TrenchBroom GenerateVersion)
 
-ADD_DEPENDENCIES(TrenchBroom GenerateHelp)
+#ADD_DEPENDENCIES(TrenchBroom GenerateHelp)
 
 IF(APPLE)
     # Configure variables that are substituted into the plist
@@ -136,14 +136,15 @@ IF(WIN32)
 	)
 ENDIF()
 
-# Properly link to OpenGL libraries on Linux
-IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
+# Properly link to OpenGL libraries on Unix-like systems
+IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux|FreeBSD")
     FIND_PACKAGE(OpenGL)
+    INCLUDE_DIRECTORIES(SYSTEM ${OPENGL_INCLUDE_DIR})
     TARGET_LINK_LIBRARIES(TrenchBroom ${OPENGL_LIBRARIES})
 ENDIF()
 
 # Set up the resources and DLLs for the executable
-IF(WIN32 OR ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
+IF(WIN32 OR ${CMAKE_SYSTEM_NAME} MATCHES "Linux|FreeBSD")
 	# Copy button images to resources directory
 	ADD_CUSTOM_COMMAND(TARGET TrenchBroom POST_BUILD
         COMMAND ${CMAKE_COMMAND} -E copy_directory "${APP_DIR}/resources/graphics/images" "$<TARGET_FILE_DIR:TrenchBroom>/Resources/images"
