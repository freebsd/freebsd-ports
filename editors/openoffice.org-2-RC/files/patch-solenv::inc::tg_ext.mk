--- ../solenv/inc/tg_ext.mk.orig	Wed Nov 14 13:59:42 2001
+++ ../solenv/inc/tg_ext.mk	Mon Mar  4 17:30:39 2002
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
