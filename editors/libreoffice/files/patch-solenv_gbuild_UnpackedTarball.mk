--- solenv/gbuild/UnpackedTarball.mk.orig	2016-10-28 14:50:26 UTC
+++ solenv/gbuild/UnpackedTarball.mk
@@ -20,6 +20,7 @@ $(GNUTAR) \
 	-x \
 	$(3) \
 	-C $(UNPACKED_DIR) \
+	--no-same-owner --no-same-permissions \
 	$(STRIP_COMPONENTS)=$(UNPACKED_STRIP_COMPONENTS) \
 	-f $(UNPACKED_TARBALL)
 endef
