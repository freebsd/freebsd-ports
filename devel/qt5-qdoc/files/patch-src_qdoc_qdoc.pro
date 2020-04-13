--- src/qdoc/qdoc.pro.orig	2019-12-31 21:11:48 UTC
+++ src/qdoc/qdoc.pro
@@ -152,6 +152,6 @@ cmake_qdoc_config_version_file.output = $$MODULE_BASE_
 QMAKE_SUBSTITUTES += cmake_qdoc_config_file cmake_qdoc_config_version_file
 
 cmake_qdoc_tools_files.files += $$cmake_qdoc_config_file.output $$cmake_qdoc_config_version_file.output
-cmake_qdoc_tools_files.path = $$[QT_INSTALL_LIBS]/cmake/Qt5DocTools
+cmake_qdoc_tools_files.path = $$[QT_INSTALL_PREFIX]/lib/cmake/Qt5DocTools
 cmake_qdoc_tools_files.CONFIG = no_check_exist
 INSTALLS += cmake_qdoc_tools_files
