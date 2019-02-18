--- cmake/install.cmake.orig	2019-02-18 06:48:48 UTC
+++ cmake/install.cmake
@@ -45,7 +45,7 @@ install(DIRECTORY include/OpenImageDenoi
 ## Install documentation
 ## ----------------------------------------------------------------------------
 
-install(FILES ${PROJECT_SOURCE_DIR}/LICENSE.txt DESTINATION ${CMAKE_INSTALL_DOCDIR} COMPONENT lib)
+#install(FILES ${PROJECT_SOURCE_DIR}/LICENSE.txt DESTINATION ${CMAKE_INSTALL_DOCDIR} COMPONENT lib)
 install(FILES ${PROJECT_SOURCE_DIR}/CHANGELOG.md DESTINATION ${CMAKE_INSTALL_DOCDIR} COMPONENT lib)
 install(FILES ${PROJECT_SOURCE_DIR}/README.md DESTINATION ${CMAKE_INSTALL_DOCDIR} COMPONENT lib)
 install(FILES ${PROJECT_SOURCE_DIR}/readme.pdf DESTINATION ${CMAKE_INSTALL_DOCDIR} COMPONENT lib)
