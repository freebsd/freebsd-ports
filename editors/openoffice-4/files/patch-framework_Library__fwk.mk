--- framework/Library_fwk.mk.orig	2017-11-27 17:03:35 UTC
+++ framework/Library_fwk.mk
@@ -187,7 +187,8 @@ $(eval $(call gb_Library_add_exception_objects,fwk,\
 ))
 
 # i126622 - Base 4.1.2 does not open Tables and Queries in Mac OSX
-ifeq ($(OS),MACOSX)
+# Also appears to affect FreeBSD 10.3 with clang 3.4.1.
+ifeq ($(COM)$(CPUNAME),CLANGX86_64)
     $(call gb_CxxObject_get_target,framework/source/loadenv/loadenv):\
 	CXXFLAGS := $(gb_LinkTarget_CXXFLAGS) $(gb_LinkTarget_EXCEPTIONFLAGS) $(gb_COMPILERNOOPTFLAGS)
 endif
