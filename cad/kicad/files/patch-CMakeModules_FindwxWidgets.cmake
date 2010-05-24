--- CMakeModules/FindwxWidgets.cmake.orig	2010-04-13 20:11:02.000000000 +0200
+++ CMakeModules/FindwxWidgets.cmake	2010-05-23 14:24:35.000000000 +0200
@@ -116,13 +116,14 @@
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
@@ -698,9 +699,10 @@
         DBG_MSG_V("wxWidgets_CXX_FLAGS=${wxWidgets_CXX_FLAGS}")
 
         # parse definitions from cxxflags; drop -D* from CXXFLAGS
-        STRING(REGEX MATCHALL "-D[^;]+"
+	# + handle -pthread like a -D to avoid ';' among the flags
+        STRING(REGEX MATCHALL "-[Dp][^;]+"
           wxWidgets_DEFINITIONS  "${wxWidgets_CXX_FLAGS}")
-        STRING(REGEX REPLACE "-D[^;]+;" ""
+        STRING(REGEX REPLACE "-[Dp][^;]+;" ""
           wxWidgets_CXX_FLAGS "${wxWidgets_CXX_FLAGS}")
 
         # parse include dirs from cxxflags; drop -I prefix
