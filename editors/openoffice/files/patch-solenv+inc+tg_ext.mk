--- ../solenv/inc/tg_ext.mk.orig	Wed Nov 14 13:59:42 2001
+++ ../solenv/inc/tg_ext.mk	Mon Mar  4 17:30:39 2002
@@ -107,7 +107,7 @@
 	
 $(MISC)$/%.unpack : $(PRJ)$/download$/%.tar.gz
 	@+-$(RM) $@
-	@+echo $(assign UNPACKCMD := gunzip -c $(BACK_PATH)download$/$(TARFILE_NAME).tar.gz | tar $(TAR_EXCLUDE_SWITCH) -xvf - ) > $(NULLDEV)
+	@+echo $(assign UNPACKCMD := tar $(TAR_EXCLUDE_SWITCH) -xzvf $(BACK_PATH)download$/$(TARFILE_NAME).tar.gz ) > $(NULLDEV)
 	@+$(COPY) $(mktmp $(UNPACKCMD)) $@
 
 $(MISC)$/%.unpack : $(PRJ)$/download$/%.tar
@@ -148,7 +148,11 @@
 .IF "$(BSCLIENT)"=="TRUE"
 	+cd $(PACKAGE_DIR) && $(TYPE) $(BACK_PATH)$(PATCH_FILE_NAME) | $(GNUPATCH) -f -b -p2 && $(TOUCH) $(PATCH_FLAG_FILE)
 .ELSE           # "$(BSCLIENT)"!=""
+.IF "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
+	+cd $(PACKAGE_DIR) && $(TYPE) $(BACK_PATH)$(PATCH_FILE_NAME) | patch -p2 && $(TOUCH) $(PATCH_FLAG_FILE)
+.ELSE
 	+cd $(PACKAGE_DIR) && $(TYPE) $(BACK_PATH)$(PATCH_FILE_NAME) | patch -b -p2 && $(TOUCH) $(PATCH_FLAG_FILE)
+.ENDIF          # "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
 .ENDIF          # "$(BSCLIENT)"!=""
 .ENDIF          # "$(GUI)"=="WNT"
 .ENDIF			# "$(PATCH_FILE_NAME)"=="none" ||	"$(PATCH_FILE_NAME)"==""
