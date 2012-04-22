--- ./desktop/Executable_unopkg.bin.mk.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./desktop/Executable_unopkg.bin.mk	2012-04-16 14:24:48.000000000 +0200
@@ -43,6 +43,7 @@
 $(eval $(call gb_Executable_add_linked_libs,$(unopkgbin),\
     comphelper \
     sal \
+    pthread \
     tl \
     unopkgapp \
 ))
