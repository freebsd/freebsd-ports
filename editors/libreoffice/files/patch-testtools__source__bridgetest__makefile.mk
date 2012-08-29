--- ./testtools/source/bridgetest/makefile.mk.orig	2012-08-08 09:00:06.000000000 -0400
+++ ./testtools/source/bridgetest/makefile.mk	2012-08-27 15:06:28.000000000 -0400
@@ -31,7 +31,6 @@
 TARGET=bridgetest
 USE_DEFFILE=TRUE
 ENABLE_EXCEPTIONS=TRUE
-VISIBILITY_HIDDEN=TRUE
 LIBTARGET=NO
 
 .INCLUDE: settings.mk
@@ -145,16 +144,6 @@
 
 runtest : $(DLLDEST)$/uno_types.rdb $(DLLDEST)$/uno_services.rdb makefile.mk \
         $(SHL1TARGETN) $(SHL2TARGETN) $(SHL3TARGETN)
-.IF "$(CROSS_COMPILING)"!="YES"
-.IF "$(COM)$(OS)$(CPU)" == "GCCMACOSXP"
-    @echo "Mac OSX PPC GCC fails this test!, likely broken UNO bridge. Fix me."
-.ELSE
-        cd $(DLLDEST) && $(AUGMENT_LIBRARY_PATH) $(SOLARBINDIR)/uno \
-        -ro uno_services.rdb -ro uno_types.rdb \
-        -s com.sun.star.test.bridge.BridgeTest -- \
-        com.sun.star.test.bridge.CppTestObject
-.ENDIF
-.ENDIF
 
 $(DLLDEST)/services.rdb :
     $(COPY) $(SOLARXMLDIR)/ure/services.rdb $@
