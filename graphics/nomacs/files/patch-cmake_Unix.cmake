Sent upstream: https://github.com/nomacs/nomacs/pull/187

From 6617595f409f13f035895f6494a4d8e14047334e Mon Sep 17 00:00:00 2001
From: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date: Mon, 29 Jan 2018 12:01:50 +0100
Subject: [PATCH] cmake: Stop calling QT5_WRAP_CPP() when building quazip and
 libqpsd.

cmake/Utils.cmake already sets CMAKE_AUTOMOC to on.

Calling QT5_WRAP_CPP() used to be just redundant, as QUAZIP_MOC_SRC and
LIBQPSD_MOC_SRC were never actually added as source dependencies in
MacBuildTarget.cmake and UnixBuildTarget.cmake. In other words, CMake's own
automoc infrastructure was actually being used and the moc invocations from
QT5_WRAP_CPP() were not being made at all.

Starting with Qt 5.9.4, calling QT5_WRAP_CPP() disables the AUTOMOC property
on the macro's input files, which means neither CMake's automoc
infrastructure not QT5_WRAP_CPP()'s code were being used and we ended up
with several 'undefined reference to vtable' errors when linking.
--- cmake/Unix.cmake.orig	2017-03-24 14:47:13 UTC
+++ cmake/Unix.cmake
@@ -97,7 +97,6 @@ unset(QUAZIP_LIBRARIES CACHE)
 
 unset(QUAZIP_HEADERS CACHE)
 unset(QUAZIP_SOURCES CACHE)
-unset(QUAZIP_MOCS CACHE)
 unset(QT_ROOT CACHE)
 
 if(ENABLE_QUAZIP)
@@ -116,9 +115,7 @@ if(ENABLE_QUAZIP)
 
     file(GLOB QUAZIP_SOURCES "3rdparty/quazip-0.7/quazip/*.c" "3rdparty/quazip-0.7/quazip/*.cpp")
     file(GLOB QUAZIP_HEADERS "3rdparty/quazip-0.7/quazip/*.h")
-    file(GLOB QUAZIP_MOCS "3rdparty/quazip-0.7/quazip/*.h")
 
-    QT5_WRAP_CPP(QUAZIP_MOC_SRC ${QUAZIP_MOCS})
     add_definitions(-DWITH_QUAZIP)
   endif(USE_SYSTEM_QUAZIP)
 endif(ENABLE_QUAZIP)
@@ -132,6 +129,4 @@ IF(USE_SYSTEM_LIBQPSD)
 ELSE()
 	file(GLOB LIBQPSD_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/libqpsd/*.cpp")
 	file(GLOB LIBQPSD_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/libqpsd/*.h")
-	file(GLOB LIBQPSD_MOCS "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/libqpsd/*.h")
-	QT5_WRAP_CPP(LIBQPSD_MOC_SRC ${LIBQPSD_MOCS})
 ENDIF(USE_SYSTEM_LIBQPSD)
