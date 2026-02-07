--- svx/Executable_gengal.mk.orig	2022-01-26 14:35:29 UTC
+++ svx/Executable_gengal.mk
@@ -33,6 +33,8 @@ ifneq (,$(filter-out MACOSX WNT,$(OS)))
 $(eval $(call gb_Executable_use_package,gengal,svx_gengal))
 endif
 
+$(eval $(call gb_Executable_use_externals,gengal,orcus))
+
 $(eval $(call gb_Executable_use_libraries,gengal,\
     basegfx \
     sal \
