--- modules/web/src/main/native/Source/WebCore/PlatformJava.cmake.orig	2018-03-23 23:53:57 UTC
+++ modules/web/src/main/native/Source/WebCore/PlatformJava.cmake
@@ -188,8 +188,8 @@ elseif (APPLE)
 endif ()
 
 list(APPEND WebCore_LIBRARIES
-    XMLJava
-    XSLTJava
+    ${CMAKE_INSTALL_PREFIX}/lib/libxml2.so
+    ${CMAKE_INSTALL_PREFIX}/lib/libxslt.so
 )
 
 list(APPEND WebCore_USER_AGENT_STYLE_SHEETS
@@ -225,7 +225,7 @@ set(WebCore_FORWARDING_HEADERS_FILES
 set(WebCore_USER_AGENT_SCRIPTS_DEPENDENCIES ${WEBCORE_DIR}/platform/java/RenderThemeJava.cpp)
 
 list(APPEND WebCore_LIBRARIES
-    SqliteJava
+    ${CMAKE_INSTALL_PREFIX}/lib/libsqlite3.so
     ${ICU_I18N_LIBRARIES}
     ${ICU_LIBRARIES}
 )
