--- ./shell/Module_shell.mk.orig	2013-01-31 05:54:53.000000000 -0500
+++ ./shell/Module_shell.mk	2013-02-19 20:26:39.000000000 -0500
@@ -32,7 +32,7 @@
 	Library_localebe \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(GUI),UNX)
 ifeq ($(ENABLE_GIO),TRUE)
 $(eval $(call gb_Module_add_targets,shell,\
 	Library_losessioninstall \
