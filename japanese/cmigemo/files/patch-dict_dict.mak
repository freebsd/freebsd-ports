--- dict/dict.mak.orig	2014-12-20 04:39:02 UTC
+++ dict/dict.mak
@@ -15,7 +15,7 @@ UTF8_DIR	= utf-8.d
 # Dictionary
 #
 $(DICT): $(DICT_BASE)
-	$(FILTER_CP932) < $(DICT_BASE) > $@
+	$(ICONV_EUCJP_TO_CP932) < $(DICT_BASE) > $@
 $(DICT_BASE): $(SKKDIC_FILE) ../tools/skk2migemo.pl ../tools/optimize-dict.pl
 	$(PERL) ../tools/skk2migemo.pl < $(SKKDIC_FILE) > dict.tmp
 	$(PERL) ../tools/optimize-dict.pl < dict.tmp > $@
@@ -32,42 +32,42 @@ cp932:		$(DICT)
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
-	$(FILTER_EUCJP) < migemo-dict > $@
+	$(ICONV_CP932_TO_EUCJP) < migemo-dict > $@
 $(EUCJP_DIR)/zen2han.dat: zen2han.dat
-	$(FILTER_EUCJP) < zen2han.dat > $@
+	$(ICONV_CP932_TO_EUCJP) < zen2han.dat > $@
 $(EUCJP_DIR)/han2zen.dat: han2zen.dat
-	$(FILTER_EUCJP) < han2zen.dat > $@
+	$(ICONV_CP932_TO_EUCJP) < han2zen.dat > $@
 $(EUCJP_DIR)/hira2kata.dat: hira2kata.dat
-	$(FILTER_EUCJP) < hira2kata.dat > $@
+	$(ICONV_CP932_TO_EUCJP) < hira2kata.dat > $@
 $(EUCJP_DIR)/roma2hira.dat: roma2hira.dat
-	$(FILTER_EUCJP) < roma2hira.dat > $@
+	$(ICONV_CP932_TO_EUCJP) < roma2hira.dat > $@
 
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
-	$(FILTER_UTF8) < migemo-dict > $@
+	$(ICONV_CP932_TO_UTF8) < migemo-dict > $@
 $(UTF8_DIR)/zen2han.dat: zen2han.dat
-	$(FILTER_UTF8) < zen2han.dat > $@
+	$(ICONV_CP932_TO_UTF8) < zen2han.dat > $@
 $(UTF8_DIR)/han2zen.dat: han2zen.dat
-	$(FILTER_UTF8) < han2zen.dat > $@
+	$(ICONV_CP932_TO_UTF8) < han2zen.dat > $@
 $(UTF8_DIR)/hira2kata.dat: hira2kata.dat
-	$(FILTER_UTF8) < hira2kata.dat > $@
+	$(ICONV_CP932_TO_UTF8) < hira2kata.dat > $@
 $(UTF8_DIR)/roma2hira.dat: roma2hira.dat
-	$(FILTER_UTF8) < roma2hira.dat > $@
+	$(ICONV_CP932_TO_UTF8) < roma2hira.dat > $@
 
 ##############################################################################
 # for Microsoft Visual C
@@ -92,7 +92,8 @@ mingw:		cp932 utf-8
 ##############################################################################
 # for GNU/gcc(Linux‘¼)
 #
-gcc:		euc-jp utf-8
+gcc-dict:		euc-jp-dict utf-8-dict
+gcc-dat:		euc-jp-dat utf-8-dat
 
 ##############################################################################
 # for MacOS X
