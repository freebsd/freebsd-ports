BASHCOMP_SCRIPT doesn't really require bash.

--- cmake/modules/BashCompletion.cmake.orig	2019-02-19 07:43:51 UTC
+++ cmake/modules/BashCompletion.cmake
@@ -71,7 +71,7 @@ ELSE()
 		SET(BASHCOMP_SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/install_${SCRIPT_NAME}_completion.sh")
 
 		FILE(WRITE ${BASHCOMP_SCRIPT} "\
-#!${BASH}\n\
+#!/bin/sh\n\
 set -e\n\
 if [ -w \"${BASHCOMP_PKG_PATH}\" ]; then\n\
   BASHCOMP_PKG_PATH=\"${BASHCOMP_PKG_PATH}\"\n\
