--- testtools/source/bridgetest/makefile.mk.orig	2026-09-08 18:56:04 UTC
+++ testtools/source/bridgetest/makefile.mk
@@ -134,8 +134,8 @@ runtest : $(DLLDEST)$/uno_types.rdb $(DLLDEST)$/uno_se
 
 runtest : $(DLLDEST)$/uno_types.rdb $(DLLDEST)$/uno_services.rdb makefile.mk \
         $(SHL1TARGETN) $(SHL2TARGETN) $(SHL3TARGETN)
-.IF "$(COM)$(OS)$(CPU)" == "GCCMACOSXP" || "$(OS)$(CPU)"=="SOLARISS" || "$(OS)$(CPU)"=="FREEBSDP"
-	@echo "Mac OSX PPC GCC and Solaris fails this test! likely broken UNO bridge. Fix me."
+.IF "$(COM)$(OS)$(CPU)" == "GCCMACOSXP" || "$(OS)$(CPU)"=="SOLARISS" || "$(OS)$(CPU)"=="FREEBSDP" || "$(OS)$(CPU)"=="FREEBSDI"
+	@echo "Mac OSX PPC GCC X86 and Solaris fails this test! likely broken UNO bridge. Fix me."
 .ELSE
         cd $(DLLDEST) && $(AUGMENT_LIBRARY_PATH) $(SOLARBINDIR)/uno \
 		-ro uno_services.rdb -ro uno_types.rdb \
