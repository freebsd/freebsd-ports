--- cmake/SIPMacros.cmake.orig	2020-08-28 05:25:49 UTC
+++ cmake/SIPMacros.cmake
@@ -121,6 +121,12 @@ MACRO(GENERATE_SIP_PYTHON_MODULE_CODE MODULE_NAME MODU
     DEPENDS ${SIP_EXTRA_FILES_DEPEND}
     VERBATIM
   )
+  IF (SIP_MODULE_EXECUTABLE)
+    ADD_CUSTOM_COMMAND(
+      OUTPUT ${_sip_output_files} APPEND
+      COMMAND ${SIP_MODULE_EXECUTABLE} --target-dir ${CMAKE_CURRENT_BINARY_DIR}/${_module_path} --sip-h ${PYQT5_SIP_IMPORT}
+    )
+  ENDIF (SIP_MODULE_EXECUTABLE)
 
   ADD_CUSTOM_TARGET(generate_sip_${MODULE_NAME}_cpp_files DEPENDS ${_sip_output_files})
 
