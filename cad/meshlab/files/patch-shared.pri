--- shared.pri.orig	2012-07-31 07:43:04.000000000 +0200
+++ shared.pri	2013-10-31 12:18:49.000000000 +0100
@@ -72,3 +72,5 @@
 	win32-msvc2005: RCC_DIR = $(ConfigurationName)
 	win32-msvc2008: RCC_DIR = $(ConfigurationName)
 	win32-msvc2010: RCC_DIR = $(ConfigurationName)
+
+LIBS+=../../common/libcommon.a
