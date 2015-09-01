--- Repository.mk.orig	2015-08-22 06:41:35 UTC
+++ Repository.mk
@@ -68,7 +68,7 @@ $(eval $(call gb_Helper_register_executa
         svpclient \
         pixelctl ) \
 	$(if $(and $(ENABLE_GTK), $(filter LINUX,$(OS))), tilebench) \
-	$(if $(filter LINUX MACOSX WNT,$(OS)),icontest \
+	$(if $(filter FREEBSD LINUX MACOSX WNT,$(OS)),icontest \
 	    outdevgrind) \
 	vcldemo \
 	tiledrendering \
