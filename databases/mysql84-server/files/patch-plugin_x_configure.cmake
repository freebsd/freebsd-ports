--- plugin/x/configure.cmake.orig	2024-04-10 06:26:28 UTC
+++ plugin/x/configure.cmake
@@ -46,6 +46,7 @@ CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src/config/mysqlx
 CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src/config/mysqlx_version.h.in
                ${MYSQLX_GENERATE_DIR}/mysqlx_version.h )
 
+IF(FALSE)
 INSTALL(FILES ${MYSQLX_GENERATE_DIR}/mysqlx_error.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Development)
@@ -57,3 +58,4 @@ INSTALL(FILES ${MYSQLX_GENERATE_DIR}/mysqlx_version.h
 INSTALL(FILES ${MYSQLX_GENERATE_DIR}/mysqlx_version.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Development)
+ENDIF()
