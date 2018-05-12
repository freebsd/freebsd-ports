--- plugin/x/configure.cmake.orig	2018-04-08 06:44:49 UTC
+++ plugin/x/configure.cmake
@@ -44,6 +44,7 @@ CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src
 CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src/mysqlx_version.h.in
                ${MYSQLX_GENERATE_DIR}/mysqlx_version.h )
 
+IF(FALSE)
 INSTALL(FILES ${MYSQLX_GENERATE_DIR}/mysqlx_error.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Development)
@@ -55,3 +56,4 @@ INSTALL(FILES ${MYSQLX_GENERATE_DIR}/mys
 INSTALL(FILES ${MYSQLX_GENERATE_DIR}/mysqlx_version.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Development)
+ENDIF()
