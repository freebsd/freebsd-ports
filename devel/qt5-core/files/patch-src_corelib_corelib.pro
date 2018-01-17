As we moved the libraries of Qt5 from /usr/local/lib to  /usr/local/lib/qt5 the
cmake files would get installed into /usr/local/lib/qt5/cmake. This however is
not really convenient for use with other applications depending on Qt via cmake.

For ports we could modify cmake.mk to always append /usr/local/lib/qt5 to the
search path. This would however still break applications outside of the ports
tree that users want to compile via cmake. An other option would be to patch
devel/cmake to add /usr/local/lib/qt5/cmake to the default search paths.

We chose the third option. To patch qmake's internal cmake generation function
to fix up the paths so that cmake files still land in the the "correct" location
in /usr/local/lib/cmake -- as this seemed to be the least intrusive method.


--- src/corelib/corelib.pro.orig	2017-06-28 11:54:29.000000000 +0200
+++ src/corelib/corelib.pro	2017-07-20 23:06:37.223900000 +0200
@@ -130,7 +130,7 @@
     $$cmake_umbrella_config_version_file.output \
     $$cmake_umbrella_config_module_location_for_install.output
 
-cmake_qt5_umbrella_module_files.path = $$[QT_INSTALL_LIBS]/cmake/Qt5
+cmake_qt5_umbrella_module_files.path = $$[QT_INSTALL_PREFIX]/lib/cmake/Qt5
 
 QMAKE_SUBSTITUTES += \
     ctest_macros_file \
@@ -143,6 +143,6 @@
 
 ctest_qt5_module_files.files += $$ctest_macros_file.output $$cmake_extras_mkspec_dir_for_install.output
 
-ctest_qt5_module_files.path = $$[QT_INSTALL_LIBS]/cmake/Qt5Core
+ctest_qt5_module_files.path = $$[QT_INSTALL_PREFIX]/lib/cmake/Qt5Core
 
 INSTALLS += ctest_qt5_module_files cmake_qt5_umbrella_module_files
