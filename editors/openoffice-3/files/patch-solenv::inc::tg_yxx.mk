--- ../solenv/inc/tg_yxx.mk.orig	Wed Sep 20 16:43:18 2000
+++ ../solenv/inc/tg_yxx.mk	Wed Mar  6 10:47:24 2002
@@ -4,7 +4,9 @@
 	@echo ------------------------------
 	@echo Making: $@
 #.IF "$(GUI)"!="UNX"
+	$(BISON) $(YACCFLAGS) $(YACCOUT)$/$(YACCTARGET).h $(YACCFILES)
 	$(BISON) $(YACCFLAGS) $(YACCOUT)$/$(YACCTARGET) $(YACCFILES)
+	$(BISON) -o $(YACCOUT)$/$(YACCTARGET) $(YACCFILES)
 #.ELSE
 #	$(BISON) $(YACCFLAGS) $(YACCFILES)
 #	mv y.tab.c $(INCCOM)/rscyacc.yxx
