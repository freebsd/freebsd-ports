--- ../solenv/inc/tg_ext.mk.orig	Tue Mar 19 12:43:51 2002
+++ ../solenv/inc/tg_ext.mk	Wed Apr  3 01:31:10 2002
@@ -108,7 +108,7 @@
 	
 $(MISC)$/%.unpack : $(PRJ)$/download$/%.tar.gz
 	@+-$(RM) $@
-	@+echo $(assign UNPACKCMD := gunzip -c $(BACK_PATH)download$/$(TARFILE_NAME).tar.gz | tar $(TAR_EXCLUDE_SWITCH) -xvf - ) > $(NULLDEV)
+	@+echo $(assign UNPACKCMD := tar $(TAR_EXCLUDE_SWITCH) -xzvf $(BACK_PATH)download$/$(TARFILE_NAME).tar.gz ) > $(NULLDEV)
 	@+$(COPY) $(mktmp $(UNPACKCMD)) $@
 
 $(MISC)$/%.unpack : $(PRJ)$/download$/%.tar
@@ -147,17 +147,17 @@
 	+cd $(PACKAGE_DIR) && $(TYPE) $(BACK_PATH)$(PATCH_FILE_NAME) | tr -d "\015" | patch -b -p2 && $(TOUCH) $(PATCH_FLAG_FILE)
 .ELSE           # "$(GUI)"=="WNT"
 .IF "$(BSCLIENT)"=="TRUE"
-.IF "$(OS)"=="NETBSD"
+.IF "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
 	+cd $(PACKAGE_DIR) && $(TYPE) $(BACK_PATH)$(PATCH_FILE_NAME) | $(GNUPATCH) -f -p2 && $(TOUCH) $(PATCH_FLAG_FILE)
 .ELSE
 	+cd $(PACKAGE_DIR) && $(TYPE) $(BACK_PATH)$(PATCH_FILE_NAME) | $(GNUPATCH) -f -b -p2 && $(TOUCH) $(PATCH_FLAG_FILE)
-.ENDIF		# "$(OS)"=="NETBSD"
+.ENDIF		# "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
 .ELSE           # "$(BSCLIENT)"!=""
-.IF "$(OS)"=="NETBSD"
+.IF "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
 	+cd $(PACKAGE_DIR) && $(TYPE) $(BACK_PATH)$(PATCH_FILE_NAME) | patch -p2 && $(TOUCH) $(PATCH_FLAG_FILE)
 .ELSE
 	+cd $(PACKAGE_DIR) && $(TYPE) $(BACK_PATH)$(PATCH_FILE_NAME) | patch -b -p2 && $(TOUCH) $(PATCH_FLAG_FILE)
-.ENDIF          # "$(OS)"=="NETBSD"
+.ENDIF          # "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
 .ENDIF          # "$(BSCLIENT)"!=""
 .ENDIF          # "$(GUI)"=="WNT"
 .ENDIF			# "$(PATCH_FILE_NAME)"=="none" ||	"$(PATCH_FILE_NAME)"==""
