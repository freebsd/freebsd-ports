--- ../solenv/inc/tg_ext.mk.orig	Sun Mar  3 19:47:04 2002
+++ ../solenv/inc/tg_ext.mk	Sun Mar  3 19:47:08 2002
@@ -148,7 +148,11 @@
 .IF "$(BSCLIENT)"=="TRUE"
 	+cd $(PACKAGE_DIR) && $(TYPE) $(BACK_PATH)$(PATCH_FILE_NAME) | $(GNUPATCH) -f -b -p2 && $(TOUCH) $(PATCH_FLAG_FILE)
 .ELSE           # "$(BSCLIENT)"!=""
+.IF "$(OS)"=="FREEBSD"
 	+cd $(PACKAGE_DIR) && $(TYPE) $(BACK_PATH)$(PATCH_FILE_NAME) | patch -b -p2 && $(TOUCH) $(PATCH_FLAG_FILE)
+.ELSE
+	+cd $(PACKAGE_DIR) && $(TYPE) $(BACK_PATH)$(PATCH_FILE_NAME) | patch -p2 && $(TOUCH) $(PATCH_FLAG_FILE)
+.ENDIF
 .ENDIF          # "$(BSCLIENT)"!=""
 .ENDIF          # "$(GUI)"=="WNT"
 .ENDIF			# "$(PATCH_FILE_NAME)"=="none" ||	"$(PATCH_FILE_NAME)"==""
