--- vcl/Module_vcl.mk.orig	2015-08-22 06:41:35 UTC
+++ vcl/Module_vcl.mk
@@ -27,7 +27,7 @@ $(eval $(call gb_Module_add_targets,vcl,
         StaticLibrary_vclmain \
 		$(if $(ENABLE_HEADLESS),, \
 			Executable_ui-previewer) \
-		$(if $(filter LINUX MACOSX WNT,$(OS)), \
+		$(if $(filter FREEBSD LINUX MACOSX WNT,$(OS)), \
 			Executable_outdevgrind \
 			$(if $(ENABLE_HEADLESS),, \
 				Executable_vcldemo \
