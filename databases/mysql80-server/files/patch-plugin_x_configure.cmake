--- plugin/x/configure.cmake.orig	2019-09-20 08:30:51 UTC
+++ plugin/x/configure.cmake
@@ -45,6 +45,7 @@ CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src/config/mysqlx
 CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src/config/mysqlx_version.h.in
                ${MYSQLX_GENERATE_DIR}/mysqlx_version.h )
 
+IF(FALSE)
 INSTALL(FILES ${MYSQLX_GENERATE_DIR}/mysqlx_error.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Development)
@@ -56,3 +57,4 @@ INSTALL(FILES ${MYSQLX_GENERATE_DIR}/mysqlx_ername.h
 INSTALL(FILES ${MYSQLX_GENERATE_DIR}/mysqlx_version.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Development)
+ENDIF()
