--- rapid/plugin/x/mysqlx_configure.cmake.orig	2016-09-14 15:25:26 UTC
+++ rapid/plugin/x/mysqlx_configure.cmake
@@ -29,6 +29,7 @@ CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src
 CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src/mysqlx_version.h.in
                ${CMAKE_CURRENT_BINARY_DIR}/generated/mysqlx_version.h )
 
+IF(FALSE)
 INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/generated/mysqlx_error.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Developement)
@@ -36,3 +37,4 @@ INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR
 INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/generated/mysqlx_version.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Developement)
+ENDIF()
