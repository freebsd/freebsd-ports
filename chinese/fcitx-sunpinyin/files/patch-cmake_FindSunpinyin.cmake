--- cmake/FindSunpinyin.cmake~	2012-03-04 21:43:53.000000000 -0600
+++ cmake/FindSunpinyin.cmake	2012-04-06 02:14:47.564463773 -0500
@@ -16,7 +16,7 @@ if(SUNPINYIN_INCLUDE_DIR AND SUNPINYIN_L
 endif(SUNPINYIN_INCLUDE_DIR AND SUNPINYIN_LIBRARIES)
 
 find_package(PkgConfig REQUIRED)
-pkg_check_modules(PC_LIBSUNPINYIN "sunpinyin-2.0 >= 2.0.4")
+pkg_check_modules(PC_LIBSUNPINYIN "sunpinyin-2.0 >= 2.0.3")
 
 find_path(SUNPINYIN_MAIN_INCLUDE_DIR
           NAMES sunpinyin.h
