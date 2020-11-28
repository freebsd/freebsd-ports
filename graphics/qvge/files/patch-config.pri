--- config.pri.orig	2020-11-09 05:38:47 UTC
+++ config.pri
@@ -6,7 +6,7 @@
 # It can be used freely, maintaining the information above.
 
 #CONFIG += USE_OGDF
-CONFIG += USE_GVGRAPH
+#CONFIG += USE_GVGRAPH
 #CONFIG += USE_BOOST
 
 
@@ -15,8 +15,8 @@ USE_OGDF{
     DEFINES += USE_OGDF
 
     # system-specific OGDF setup
-    OGDF_LIB_NAME = ogdf
-    OGDF_LIB_PATH =
+    OGDF_LIB_NAME = OGDF
+    OGDF_LIB_PATH = /usr/local/lib # must not be empty
     OGDF_INCLUDE_PATH = /usr/share/ogdf/include
 }
 
@@ -49,7 +49,7 @@ gcc{
 
 # common config
 QT += core gui widgets xml opengl network printsupport svg
-CONFIG += c++14
+CONFIG += c++11
 
 
 # output
