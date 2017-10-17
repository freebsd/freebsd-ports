--- modules/web/src/main/native/Source/JavaScriptCore/PlatformJava.cmake.orig	2017-09-08 16:56:55 UTC
+++ modules/web/src/main/native/Source/JavaScriptCore/PlatformJava.cmake
@@ -46,4 +46,4 @@ list(APPEND JavaScriptCore_SYSTEM_INCLUDE_DIRECTORIES
 	${JDK_INCLUDE_DIRS}
 )
 
-add_dependencies(WTF icudatagen)
+#add_dependencies(WTF icudatagen)
