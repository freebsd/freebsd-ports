--- clone/filters/oox/source/token/makefile.mk.orig	2011-05-20 16:05:36.000000000 +0000
+++ clone/filters/oox/source/token/makefile.mk	2011-08-24 21:15:27.302581359 +0000
@@ -56,7 +56,7 @@ $(MISC)$/tokenhash.gperf $(INCCOM)$/toke
 $(SLO)$/tokenmap.obj : $(INCCOM)$/tokenhash.inc $(INCCOM)$/tokennames.inc $(GENHEADERPATH)$/tokens.hxx $(MISC)$/do_tokens
 
 $(INCCOM)$/tokenhash.inc : $(MISC)$/tokenhash.gperf $(MISC)$/do_tokens
-    $(AUGMENT_LIBRARY_PATH) gperf --compare-strncmp $(MISC)$/tokenhash.gperf | $(SED) -e "s/(char\*)0/(char\*)0, 0/g" | $(GREP) -v "^#line" >$(INCCOM)$/tokenhash.inc
+    $(AUGMENT_LIBRARY_PATH) $(GPERF) --compare-strncmp $(MISC)$/tokenhash.gperf | $(SED) -e "s/(char\*)0/(char\*)0, 0/g" | $(GREP) -v "^#line" >$(INCCOM)$/tokenhash.inc
 
 $(MISC)$/do_tokens $(do_phony) : tokens.txt tokens.pl tokens.hxx.head tokens.hxx.tail $(GENHEADERPATH)$/tokens.hxx $(INCCOM)$/tokennames.inc $(MISC)$/tokenhash.gperf
     @@-$(RM) $@
