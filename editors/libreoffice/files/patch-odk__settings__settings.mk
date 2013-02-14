--- ./odk/settings/settings.mk.orig	2013-01-16 04:41:51.000000000 -0500
+++ ./odk/settings/settings.mk	2013-02-12 20:53:11.000000000 -0500
@@ -566,7 +566,7 @@
 
 CC_OUTPUT_SWITCH=-o
 
-LIBRARY_LINK_FLAGS=-shared '-Wl,-rpath,$$ORIGIN'
+LIBRARY_LINK_FLAGS=-shared '-Wl,-z,origin,-rpath,$$ORIGIN'
 COMP_LINK_FLAGS=$(LIBRARY_LINK_FLAGS)
 
 EXE_LINK_FLAGS=-Wl,--allow-shlib-undefined 
