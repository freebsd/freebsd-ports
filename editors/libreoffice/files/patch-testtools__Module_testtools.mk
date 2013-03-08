--- ./testtools/Module_testtools.mk.orig	2013-01-31 05:54:53.000000000 -0500
+++ ./testtools/Module_testtools.mk	2013-02-22 14:30:43.000000000 -0500
@@ -55,14 +55,6 @@
 #))
 #endif
 
-# FIXME: Mac OSX PPC GCC fails this test!, likely broken UNO bridge.
-# (is it still relevant?)
-ifneq ($(COM)$(OS)$(CPU),GCCMACOSXP)
-$(eval $(call gb_Module_add_check_targets,testtools,\
-	CustomTarget_uno_test \
-))
-endif
-
 endif
 
 # vim:set shiftwidth=4 softtabstop=4 expandtab:
