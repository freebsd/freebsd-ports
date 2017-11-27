--- framework/Library_fwk.mk.orig	2016-08-29 00:45:25 UTC
+++ framework/Library_fwk.mk
@@ -190,4 +190,11 @@ $(eval $(call gb_Library_add_exception_objects,fwk,\
 	framework/source/xml/imagesdocumenthandler \
 ))
 
+# i126622 - Base 4.1.2 does not open Tables and Queries in Mac OSX
+# Also affects FreeBSD 10.3 with clang 3.4.1.
+# Appears to be a clang optimization bug in versions less than 3.8.0
+ifeq ($(COM)$(CPUNAME),CLANGX86_64)
+$(call gb_CxxObject_get_target,framework/source/loadenv/loadenv):       T_CXXFLAGS := $(gb_LinkTarget_CXXFLAGS) $(gb_LinkTarget_EXCEPTIONFLAGS) $(gb_COMPILERNOOPTFLAGS)
+endif
+
 # vim: set noet sw=4 ts=4:
