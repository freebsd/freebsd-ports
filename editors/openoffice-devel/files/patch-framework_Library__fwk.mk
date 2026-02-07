--- framework/Library_fwk.mk.orig	2018-04-13 00:55:26 UTC
+++ framework/Library_fwk.mk
@@ -196,5 +196,12 @@ $(eval $(call gb_LinkTarget_set_cxx_optimization, \
 	framework/source/loadenv/loadenv, $(gb_COMPILEROPT1FLAGS) \
 ))
 endif
+# Also affects FreeBSD 10.3 with clang 3.4.1.
+# Appears to be a clang optimization bug in versions less than 3.8.0
+ifeq ($(COM)$(CPUNAME),CLANGX86_64)
+$(eval $(call gb_LinkTarget_set_cxx_optimization, \
+	framework/source/loadenv/loadenv, $(gb_COMPILEROPT1FLAGS) \
+))
+endif
 
 # vim: set noet sw=4 ts=4:
