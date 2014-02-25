--- sysui/Module_sysui.mk.orig	2014-02-05 10:04:15.000000000 -0500
+++ sysui/Module_sysui.mk	2014-02-24 14:02:40.000000000 -0500
@@ -12,7 +12,6 @@
 ifneq ($(OS),WNT)
 $(eval $(call gb_Module_add_targets,sysui,\
 	CustomTarget_share \
-	CustomTarget_slackware \
 	Package_share \
 	Package_desktop \
 	$(if $(filter rpm,$(PKGFORMAT)),CustomTarget_rpm) \
