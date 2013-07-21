--- CMake/HPHPFindLibs.cmake.orig	2013-07-12 20:00:55.000000000 +0200
+++ CMake/HPHPFindLibs.cmake	2013-07-21 20:48:54.447418294 +0200
@@ -17,6 +17,18 @@
 
 include(CheckFunctionExists)
 
+# libevent checks
+set(LIBEVENT_LIB %%LIBEVENT_LIB%%)
+set(LIBEVENT_INCLUDE_DIR %%LIBEVENT_INCLUDE_DIR%%)
+include_directories(${LIBEVENT_INCLUDE_DIR})
+
+# CURL checks
+set(CURL_LIBRARIES %%CURL_LIB%%)
+set(CURL_INCLUDE_DIR %%CURL_INCLUDE_DIR%%)
+include_directories(${CURL_INCLUDE_DIR})
+add_definitions("-DHAVE_CURL_MULTI_SELECT")
+add_definitions("-DHAVE_CURL_MULTI_WAIT")
+
 # boost checks
 find_package(Boost 1.48.0 COMPONENTS system program_options filesystem regex REQUIRED)
 include_directories(${Boost_INCLUDE_DIRS})
@@ -73,21 +85,6 @@
 find_package(PCRE REQUIRED)
 include_directories(${PCRE_INCLUDE_DIRS})
 
-# libevent checks
-find_package(LibEvent REQUIRED)
-include_directories(${LIBEVENT_INCLUDE_DIR})
-
-set(CMAKE_REQUIRED_LIBRARIES "${LIBEVENT_LIB}")
-CHECK_FUNCTION_EXISTS("evhttp_bind_socket_with_fd" HAVE_CUSTOM_LIBEVENT)
-if (NOT HAVE_CUSTOM_LIBEVENT)
-	unset(HAVE_CUSTOM_LIBEVENT CACHE)
-	unset(LIBEVENT_INCLUDE_DIR CACHE)
-	unset(LIBEVENT_LIB CACHE)
-	unset(LibEvent_FOUND CACHE)
-	message(FATAL_ERROR "Custom libevent is required with HipHop patches")
-endif ()
-set(CMAKE_REQUIRED_LIBRARIES)
-
 # GD checks
 find_package(GD REQUIRED)
 
@@ -104,21 +101,6 @@
 	add_definitions(-DHAVE_LIBXED)
 endif()
 
-# CURL checks
-find_package(CURL REQUIRED)
-include_directories(${CURL_INCLUDE_DIR})
-
-set(CMAKE_REQUIRED_LIBRARIES "${CURL_LIBRARIES}")
-CHECK_FUNCTION_EXISTS("curl_multi_select" HAVE_CURL_MULTI_SELECT)
-CHECK_FUNCTION_EXISTS("curl_multi_wait" HAVE_CURL_MULTI_WAIT)
-if (HAVE_CURL_MULTI_SELECT)
-	add_definitions("-DHAVE_CURL_MULTI_SELECT")
-endif()
-if (HAVE_CURL_MULTI_WAIT)
-	add_definitions("-DHAVE_CURL_MULTI_WAIT")
-endif()
-set(CMAKE_REQUIRED_LIBRARIES)
-
 # LibXML2 checks
 find_package(LibXml2 REQUIRED)
 include_directories(${LIBXML2_INCLUDE_DIR})
@@ -328,9 +310,14 @@
 
 if (FREEBSD)
 	FIND_LIBRARY (EXECINFO_LIB execinfo)
+	FIND_LIBRARY (GETTEXT_LIB intl)
+
 	if (NOT EXECINFO_LIB)
 		message(FATAL_ERROR "You need to install libexecinfo")
 	endif()
+	if (NOT GETTEXT_LIB)
+		message(FATAL_ERROR "You need to install gettext (libintl)")
+	endif()
 endif()
 
 if (APPLE)
@@ -396,6 +383,7 @@
 
 if (FREEBSD)
 	target_link_libraries(${target} ${EXECINFO_LIB})
+	target_link_libraries(${target} ${GETTEXT_LIB})
 endif()
 
 if (APPLE)
