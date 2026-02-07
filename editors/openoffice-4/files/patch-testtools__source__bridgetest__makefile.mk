--- testtools/source/bridgetest/makefile.mk.orig
+++ testtools/source/bridgetest/makefile.mk
@@ -134,7 +134,7 @@
 
 runtest : $(DLLDEST)$/uno_types.rdb $(DLLDEST)$/uno_services.rdb makefile.mk \
         $(SHL1TARGETN) $(SHL2TARGETN) $(SHL3TARGETN)
-.IF "$(COM)$(OS)$(CPU)" == "GCCMACOSXP" || "$(OS)$(CPU)"=="SOLARISS" || "$(COM)$(OS)$(CPU)"=="GCCFREEBSDP"
+.IF "$(COM)$(OS)$(CPU)" == "GCCMACOSXP" || "$(OS)$(CPU)"=="SOLARISS" || "$(OS)$(CPU)"=="FREEBSDP"
 	@echo "Mac OSX PPC GCC and Solaris fails this test! likely broken UNO bridge. Fix me."
 .ELSE
         cd $(DLLDEST) && $(AUGMENT_LIBRARY_PATH) $(SOLARBINDIR)/uno \

