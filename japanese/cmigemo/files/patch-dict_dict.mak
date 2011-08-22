--- dict/dict.mak.orig	2011-02-27 19:45:40.000000000 +0900
+++ dict/dict.mak	2011-08-17 01:04:58.000000000 +0900
@@ -32,10 +32,10 @@
 ##############################################################################
 # Dictionary in euc-jp
 #
-euc-jp: 	cp932 euc-jp-files
-euc-jp-files: $(EUCJP_DIR) $(EUCJP_DIR)/migemo-dict \
-	$(EUCJP_DIR)/zen2han.dat $(EUCJP_DIR)/han2zen.dat \
-	$(EUCJP_DIR)/hira2kata.dat $(EUCJP_DIR)/roma2hira.dat
+euc-jp-dict: 	cp932 $(EUCJP_DIR) $(EUCJP_DIR)/migemo-dict
+euc-jp-dat: $(EUCJP_DIR) $(EUCJP_DIR)/zen2han.dat \
+	    $(EUCJP_DIR)/han2zen.dat $(EUCJP_DIR)/hira2kata.dat \
+	    $(EUCJP_DIR)/roma2hira.dat
 $(EUCJP_DIR):
 	$(MKDIR) $(EUCJP_DIR)
 $(EUCJP_DIR)/migemo-dict: migemo-dict
@@ -52,10 +52,10 @@
 ##############################################################################
 # Dictionary in utf-8
 #
-utf-8: 	cp932 utf-8-files
-utf-8-files: $(UTF8_DIR) $(UTF8_DIR)/migemo-dict \
-	$(UTF8_DIR)/zen2han.dat $(UTF8_DIR)/han2zen.dat \
-	$(UTF8_DIR)/hira2kata.dat $(UTF8_DIR)/roma2hira.dat
+utf-8-dict: 	cp932 $(UTF8_DIR) $(UTF8_DIR)/migemo-dict
+utf-8-dat: $(UTF8_DIR) $(UTF8_DIR)/zen2han.dat \
+	   $(UTF8_DIR)/han2zen.dat $(UTF8_DIR)/hira2kata.dat \
+	   $(UTF8_DIR)/roma2hira.dat
 $(UTF8_DIR):
 	$(MKDIR) $(UTF8_DIR)
 $(UTF8_DIR)/migemo-dict: migemo-dict
@@ -87,7 +87,8 @@
 ##############################################################################
 # for GNU/gcc(Linux‘¼)
 #
-gcc:		euc-jp
+gcc-dict:		euc-jp-dict utf-8-dict
+gcc-dat:		euc-jp-dat utf-8-dat
 
 ##############################################################################
 # for MacOS X
