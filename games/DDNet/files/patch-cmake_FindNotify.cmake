--- cmake/FindNotify.cmake.orig	2020-11-19 15:17:36 UTC
+++ cmake/FindNotify.cmake
@@ -1,4 +1,9 @@
 find_package(PkgConfig QUIET)
-pkg_check_modules(NOTIFY QUIET libnotify)
+pkg_check_modules(PC_NOTIFY QUIET libnotify)
+set(NOTIFY_INCLUDE_DIRS ${PC_NOTIFY_INCLUDE_DIRS})
+foreach(lib ${PC_NOTIFY_LIBRARIES})
+	find_library(NOTIFY_LIB${lib} ${lib})
+	set(NOTIFY_LIBRARIES ${NOTIFY_LIBRARIES} ${NOTIFY_LIB${lib}})
+endforeach()
 include(FindPackageHandleStandardArgs)
 find_package_handle_standard_args(Notify DEFAULT_MSG NOTIFY_LIBRARIES NOTIFY_INCLUDE_DIRS)
