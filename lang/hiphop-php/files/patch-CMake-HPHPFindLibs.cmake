--- CMake/HPHPFindLibs.cmake.orig	2012-07-13 14:44:33.729505429 +0200
+++ CMake/HPHPFindLibs.cmake	2012-07-13 14:45:03.602507878 +0200
@@ -17,6 +17,16 @@
 
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
+
 # boost checks
 
 find_package(Boost 1.37.0 COMPONENTS system;program_options;filesystem REQUIRED)
@@ -51,21 +61,6 @@
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
 
@@ -76,21 +71,6 @@
 	# nothing for now
 endif()
 
-# CURL checks
-find_package(CURL REQUIRED)
-include_directories(${CURL_INCLUDE_DIR})
-
-set(CMAKE_REQUIRED_LIBRARIES "${CURL_LIBRARIES}")
-CHECK_FUNCTION_EXISTS("curl_multi_select" HAVE_CUSTOM_CURL)
-if (NOT HAVE_CUSTOM_CURL)
-	unset(HAVE_CUSTOM_CURL CACHE)
-	unset(CURL_INCLUDE_DIR CACHE)
-	unset(CURL_LIBRARIES CACHE)
-	unset(CURL_FOUND CACHE)
-        message(FATAL_ERROR "Custom libcurl is required with the HipHop patch")
-endif ()
-set(CMAKE_REQUIRED_LIBRARIES)
-
 # LibXML2 checks
 find_package(LibXml2 REQUIRED)
 include_directories(${LIBXML2_INCLUDE_DIR})
