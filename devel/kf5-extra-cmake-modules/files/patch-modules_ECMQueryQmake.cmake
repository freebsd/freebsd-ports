FreeBSD installs Qt5's qmake as 'qmake' and not 'qmake-qt5'.

--- modules/ECMQueryQmake.cmake.orig	2016-10-29 14:41:05 UTC
+++ modules/ECMQueryQmake.cmake
@@ -1,7 +1,7 @@
 find_package(Qt5Core QUIET)

 if (Qt5Core_FOUND)
-    set(_qmake_executable_default "qmake-qt5")
+    set(_qmake_executable_default "qmake")
 endif ()
 if (TARGET Qt5::qmake)
     get_target_property(_qmake_executable_default Qt5::qmake LOCATION)
