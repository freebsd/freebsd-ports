--- ./desktop/Executable_oosplash.mk.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./desktop/Executable_oosplash.mk	2012-04-16 14:24:48.000000000 +0200
@@ -34,6 +34,7 @@
 ))
 
 $(eval $(call gb_Executable_add_linked_libs,oosplash,\
+    pthread \
     sal \
 ))
 
