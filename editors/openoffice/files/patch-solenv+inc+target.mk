--- ../solenv/inc/target.mk.orig	Mon Aug 26 01:29:21 2002
+++ ../solenv/inc/target.mk	Mon Aug 26 01:28:23 2002
@@ -2139,7 +2139,7 @@
 
 .IF "$(COMPVERMK)"!=""
 .IF "$(UPDATER)"!=""
-"$(COMPVERMK)" : $(SOLARVERSION)$/$(INPATH)$/inc$(UPDMINOREXT)$/minormkchanged.flg
+"$(COMPVERMK)" :
 	@echo COMNAME:=$(COMNAME) > $@
 	@echo COMID:=$(COMID) >> $@
 	@echo CCNUMVER:=$(CCNUMVER) >> $@
@@ -2778,7 +2778,7 @@
 $(MISC)$/$(TARGET).dpz : $(ZIP1TARGETN) $(ZIP2TARGETN) $(ZIP3TARGETN) $(ZIP4TARGETN) $(ZIP5TARGETN) $(ZIP6TARGETN) $(ZIP7TARGETN) $(ZIP8TARGETN) $(ZIP9TARGETN)
 .ENDIF
 
-$(INCCOM)$/_version.h : $(SOLARVERSION)$/$(INPATH)$/inc$(UPDMINOREXT)$/minormkchanged.flg
+$(INCCOM)$/_version.h :
 .IF "$(GUI)"=="UNX"
 		@+echo "#define" _BUILD \"$(BUILD)\"	> $@
 		@+echo "#define" _UPD \"$(UPD)\"		>> $@
