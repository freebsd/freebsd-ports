--- modules/web/src/main/native/Source/WebCore/PlatformJava.cmake.orig	2017-09-08 16:56:55 UTC
+++ modules/web/src/main/native/Source/WebCore/PlatformJava.cmake
@@ -239,7 +239,7 @@ set(WebCore_FORWARDING_HEADERS_FILES
 set(WebCore_USER_AGENT_SCRIPTS_DEPENDENCIES ${WEBCORE_DIR}/platform/java/RenderThemeJava.cpp)
 
 list(APPEND WebCore_LIBRARIES
-    SqliteJava
+    ${CMAKE_INSTALL_PREFIX}/lib/libsqlite3.so
     ${ICU_I18N_LIBRARIES}
     ${ICU_LIBRARIES}
 )
