--- rapid/plugin/x/mysqlx_error.cmake.orig	2016-04-14 21:38:55 UTC
+++ rapid/plugin/x/mysqlx_error.cmake
@@ -26,6 +26,8 @@ GENERATE_XERRORS(${MYSQLX_PROJECT_DIR}/s
 CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src/mysqlx_error.h.in 
                ${CMAKE_CURRENT_BINARY_DIR}/mysqlx_error.h)
 
+IF(FALSE)
 INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/mysqlx_error.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Developement)
+ENDIF()
