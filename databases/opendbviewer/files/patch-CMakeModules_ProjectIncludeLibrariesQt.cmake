--- CMakeModules/ProjectIncludeLibrariesQt.cmake.orig	2024-06-18 16:17:49 UTC
+++ CMakeModules/ProjectIncludeLibrariesQt.cmake
@@ -183,6 +183,9 @@ if(QT_FOUND)
 			set(QT_LIBRARY_DIR ${QT_INCLUDE_DIR}../lib/)
 		elseif(EXISTS ${QT_INCLUDE_DIR}/../../lib)
 			set(QT_LIBRARY_DIR ${QT_INCLUDE_DIR}/../../lib)
+		elseif(EXISTS ${QT_INCLUDE_DIR}/../../../lib/qt${QT_VERSION_MAJOR})
+			# We install Qt libraries as flavored subdirectories.
+			set(QT_LIBRARY_DIR ${QT_INCLUDE_DIR}/../../../lib/qt${QT_VERSION_MAJOR})
 		else()
 			find_library(QtCore_LIBRARY_PATH libQt${QT_VERSION_MAJOR}Core.so)
 			if(QtCore_LIBRARY_PATH)
@@ -201,6 +204,9 @@ if(QT_FOUND)
 			set(QT_ROOT_DIR ${QT_LIBRARY_DIR}/..)
 		elseif(EXISTS ${QT_LIBRARY_DIR}/qt${QT_VERSION_MAJOR})
 			set(QT_ROOT_DIR ${QT_LIBRARY_DIR}/qt${QT_VERSION_MAJOR})
+		elseif(EXISTS ${QT_LIBRARY_DIR}/bin/qmake)
+			# Use our qmake binary path to mark the Qt library root directory.
+			set(QT_ROOT_DIR ${QT_LIBRARY_DIR})
 		endif()
 		if(NOT QT_ROOT_DIR)
 			message(FATAL_ERROR "Qt root path not found (include path: ${QT_INCLUDE_DIR})")
@@ -339,7 +345,7 @@ if(QT_FOUND)
 
 		if(NOT (QT_USE_VERSION LESS 5))
 			include_directories(${Qt${QT_VERSION_MAJOR}${TMP_COMPONENT}_INCLUDE_DIRS})
-			add_definitions (${Qt${QT_VERSION_MAJOR}${TMP_COMPONENT}_DEFINITIONS})
+			# add_definitions do not support generator expressions
 
 			set(QT_LIBRARIES ${QT_LIBRARIES} ${Qt${QT_VERSION_MAJOR}${TMP_COMPONENT}_LIBRARIES})
 		endif()
