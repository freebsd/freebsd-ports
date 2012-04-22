--- ./desktop/Executable_soffice.bin.mk.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./desktop/Executable_soffice.bin.mk	2012-04-16 14:24:48.000000000 +0200
@@ -42,6 +42,7 @@
 
 $(eval $(call gb_Executable_add_linked_libs,$(sofficebin),\
     sal \
+    pthread \
     sofficeapp \
 ))
 
