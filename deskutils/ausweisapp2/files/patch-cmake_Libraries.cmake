--- cmake/Libraries.cmake.orig	2024-04-10 11:44:19 UTC
+++ cmake/Libraries.cmake
@@ -147,12 +147,12 @@ if(QT_COMPONENTS)
 	find_package(${Qt} ${MIN_QT_VERSION} COMPONENTS ${QT_COMPONENTS} REQUIRED)
 endif()
 
-if(LINUX OR BSD)
-	try_run(testResult compileResult "${CMAKE_BINARY_DIR}" "${CMAKE_DIR}/tests/openssl.cpp"
-		CMAKE_FLAGS INSTALL_RPATH_USE_LINK_PATH:BOOL=ON
-		LINK_LIBRARIES ${Qt}::Network OpenSSL::Crypto OpenSSL::SSL
-		OUTPUT_VARIABLE runResult)
-	if(NOT testResult EQUAL 0)
-		message(FATAL_ERROR "Your OpenSSL library looks incompatible: ${testResult}\n${runResult}")
-	endif()
-endif()
+#if(LINUX OR BSD)
+#	try_run(testResult compileResult "${CMAKE_BINARY_DIR}" "${CMAKE_DIR}/tests/openssl.cpp"
+#		CMAKE_FLAGS INSTALL_RPATH_USE_LINK_PATH:BOOL=ON
+#		LINK_LIBRARIES ${Qt}::Network OpenSSL::Crypto OpenSSL::SSL
+#		OUTPUT_VARIABLE runResult)
+#	if(NOT testResult EQUAL 0)
+#		message(FATAL_ERROR "Your OpenSSL library looks incompatible: ${testResult}\n${runResult}")
+#	endif()
+#endif()
