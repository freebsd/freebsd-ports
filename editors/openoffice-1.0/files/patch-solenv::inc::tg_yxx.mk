--- ../solenv/inc/tg_yxx.mk.orig	Fri Feb 15 13:36:38 2002
+++ ../solenv/inc/tg_yxx.mk
@@ -4,7 +4,8 @@
 	@echo ------------------------------
 	@echo Making: $@
 #.IF "$(GUI)"!="UNX"
-	$(BISON) $(YACCFLAGS) $(YACCOUT)$/$(YACCTARGET) $(YACCFILES)
+	$(BISON) $(YACCFLAGS) $(YACCOUT)$/$(YACCTARGET).h $(YACCFILES)
+	$(BISON) -o $(YACCOUT)$/$(YACCTARGET) $(YACCFILES)
 #.ELSE
 #	$(BISON) $(YACCFLAGS) $(YACCFILES)
 #	mv y.tab.c $(INCCOM)/rscyacc.yxx
