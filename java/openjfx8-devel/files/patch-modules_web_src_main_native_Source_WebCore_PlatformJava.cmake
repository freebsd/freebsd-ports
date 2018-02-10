--- modules/web/src/main/native/Source/WebCore/PlatformJava.cmake.orig	2018-01-16 01:40:56 UTC
+++ modules/web/src/main/native/Source/WebCore/PlatformJava.cmake
@@ -242,7 +242,7 @@ set(WebCore_FORWARDING_HEADERS_FILES
 set(WebCore_USER_AGENT_SCRIPTS_DEPENDENCIES ${WEBCORE_DIR}/platform/java/RenderThemeJava.cpp)
 
 list(APPEND WebCore_LIBRARIES
-    SqliteJava
+    ${CMAKE_INSTALL_PREFIX}/lib/libsqlite3.so
     ${ICU_I18N_LIBRARIES}
     ${ICU_LIBRARIES}
 )
