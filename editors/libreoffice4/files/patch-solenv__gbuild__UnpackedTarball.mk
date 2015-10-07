--- solenv/gbuild/UnpackedTarball.mk.orig	2014-04-22 18:25:28.000000000 -0400
+++ solenv/gbuild/UnpackedTarball.mk	2014-05-07 13:33:55.000000000 -0400
@@ -33,6 +33,7 @@
 	-x \
 	$(3) \
 	-C $(UNPACKED_DIR) \
+	--no-same-owner --no-same-permissions \
 	$(STRIP_COMPONENTS)=$(UNPACKED_STRIP_COMPONENTS) \
 	-f $(UNPACKED_TARBALL)
 endef
