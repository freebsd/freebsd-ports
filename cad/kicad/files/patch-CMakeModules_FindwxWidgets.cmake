--- CMakeModules/FindwxWidgets.cmake.orig	2014-05-01 12:04:10.000000000 +0200
+++ CMakeModules/FindwxWidgets.cmake	2014-05-01 12:04:10.000000000 +0200
@@ -143,13 +143,14 @@
 #
 # Helper macro to control the debugging output globally. There are
 # two versions for controlling how verbose your output should be.
+# FreeBSD: enable debug to catch some strange behaviours...
 MACRO(DBG_MSG _MSG)
-#  MESSAGE(STATUS
-#    "${CMAKE_CURRENT_LIST_FILE}(${CMAKE_CURRENT_LIST_LINE}): ${_MSG}")
+  MESSAGE(STATUS
+    "${CMAKE_CURRENT_LIST_FILE}(${CMAKE_CURRENT_LIST_LINE}): ${_MSG}")
 ENDMACRO(DBG_MSG)
 MACRO(DBG_MSG_V _MSG)
-#  MESSAGE(STATUS
-#    "${CMAKE_CURRENT_LIST_FILE}(${CMAKE_CURRENT_LIST_LINE}): ${_MSG}")
+  MESSAGE(STATUS
+    "${CMAKE_CURRENT_LIST_FILE}(${CMAKE_CURRENT_LIST_LINE}): ${_MSG}")
 ENDMACRO(DBG_MSG_V)
 
 # Clear return values in case the module is loaded more than once.
