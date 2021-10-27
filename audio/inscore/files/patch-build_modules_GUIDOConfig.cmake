--- build/modules/GUIDOConfig.cmake.orig	2021-05-09 16:41:13 UTC
+++ build/modules/GUIDOConfig.cmake
@@ -21,9 +21,9 @@ elseif(WIN32)
 		set (GUIDO_DLL ${GUIDOLIB}/build/lib/GUIDOEngine.dll)
 	endif()		
 else()
-	set (GUIDO_LIBRARIES -L${CMAKE_CURRENT_SOURCE_DIR}/lib -lGUIDOEngine)
+	set (GUIDO_LIBRARIES -lGUIDOEngine)
 endif()
 
-file (STRINGS "${GUIDOLIB}/version.txt" GUIDO_VERSION)
-message (STATUS "Using GUIDOEngine version ${GUIDO_VERSION}")
+#file (STRINGS "${GUIDOLIB}/version.txt" GUIDO_VERSION)
+message (STATUS "Using GUIDOEngine")
 
