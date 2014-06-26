--- shell/Module_shell.mk.orig	2014-06-12 04:25:19.000000000 -0400
+++ shell/Module_shell.mk	2014-06-23 18:40:42.000000000 -0400
@@ -14,7 +14,7 @@
 	Library_localebe \
 ))
 
-ifeq ($(OS),LINUX)
+ifneq ($(filter DRAGONFLY FREEBSD LINUX NETBSD OPENBSD,$(OS)),)
 ifeq ($(ENABLE_GIO),TRUE)
 $(eval $(call gb_Module_add_targets,shell,\
 	Library_losessioninstall \
