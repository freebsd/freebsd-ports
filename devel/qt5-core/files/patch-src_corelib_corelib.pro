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



--- src/corelib/corelib.pro.orig	2017-02-04 18:51:27 UTC
+++ src/corelib/corelib.pro
@@ -113,12 +113,12 @@ cmake_extras_mkspec_dir_for_install.inpu
 cmake_extras_mkspec_dir_for_install.output = $$DESTDIR/cmake/install/Qt5Core/Qt5CoreConfigExtrasMkspecDir.cmake

 cmake_qt5_umbrella_module_files.files = $$cmake_umbrella_config_file.output $$cmake_umbrella_config_version_file.output
-cmake_qt5_umbrella_module_files.path = $$[QT_INSTALL_LIBS]/cmake/Qt5
+cmake_qt5_umbrella_module_files.path = $$[QT_INSTALL_PREFIX]/lib/cmake/Qt5

 QMAKE_SUBSTITUTES += ctest_macros_file cmake_umbrella_config_file cmake_umbrella_config_version_file cmake_extras_mkspec_dir cmake_extras_mkspec_dir_for_install

 ctest_qt5_module_files.files += $$ctest_macros_file.output $$cmake_extras_mkspec_dir_for_install.output

-ctest_qt5_module_files.path = $$[QT_INSTALL_LIBS]/cmake/Qt5Core
+ctest_qt5_module_files.path = $$[QT_INSTALL_PREFIX]/lib/cmake/Qt5Core

 INSTALLS += ctest_qt5_module_files cmake_qt5_umbrella_module_files
