--- common.mk.orig	2010-10-10 16:40:15.000000000 -0700
+++ common.mk	2010-10-10 16:40:42.000000000 -0700
@@ -256,7 +256,7 @@
 install-capi: capi pre-install-capi do-install-capi post-install-capi
 pre-install-capi:: install-prereq
 do-install-capi: $(PREP)
-	$(INSTRUBY) --make="$(MAKE)" $(INSTRUBY_ARGS) --install=capi
+	@$(NULLCMD)
 post-install-capi::
 	@$(NULLCMD)
 
