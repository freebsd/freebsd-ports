--- ../solenv/inc/target.mk.orig	Wed Mar  6 00:11:40 2002
+++ ../solenv/inc/target.mk	Wed Mar  6 00:11:52 2002
@@ -2766,7 +2766,7 @@
 $(MISC)$/$(TARGET).dpz : $(ZIP1TARGETN) $(ZIP2TARGETN) $(ZIP3TARGETN) $(ZIP4TARGETN) $(ZIP5TARGETN) $(ZIP6TARGETN) $(ZIP7TARGETN) $(ZIP8TARGETN) $(ZIP9TARGETN)
 .ENDIF
 
-$(INCCOM)$/_version.h : $(SOLARVERSION)$/$(INPATH)$/inc$(UPDMINOREXT)$/minormkchanged.flg
+$(INCCOM)$/_version.h :
 .IF "$(GUI)"=="UNX"
 		@+echo "#define" _BUILD \"$(BUILD)\"	> $@
 		@+echo "#define" _UPD \"$(UPD)\"		>> $@
