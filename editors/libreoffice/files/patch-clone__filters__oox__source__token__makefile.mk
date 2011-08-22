--- clone/filters/oox/source/token/makefile.mk.orig	2011-07-22 14:33:31.988113939 +0000
+++ clone/filters/oox/source/token/makefile.mk	2011-07-22 14:34:30.469770138 +0000
@@ -56,7 +56,7 @@
 $(SLO)$/tokenmap.obj : $(INCCOM)$/tokenhash.inc $(INCCOM)$/tokennames.inc $(GENHEADERPATH)$/tokens.hxx $(MISC)$/do_tokens
 
 $(INCCOM)$/tokenhash.inc : $(MISC)$/tokenhash.gperf $(MISC)$/do_tokens
-    $(AUGMENT_LIBRARY_PATH) gperf --compare-strncmp $(MISC)$/tokenhash.gperf | $(SED) -e "s/(char\*)0/(char\*)0, 0/g" | $(GREP) -v "^#line" >$(INCCOM)$/tokenhash.inc
+    $(AUGMENT_LIBRARY_PATH) $(GPERF) --compare-strncmp $(MISC)$/tokenhash.gperf | $(SED) -e "s/(char\*)0/(char\*)0, 0/g" | $(GREP) -v "^#line" >$(INCCOM)$/tokenhash.inc
 
 $(MISC)$/do_tokens $(do_phony) : tokens.txt tokens.pl tokens.hxx.head tokens.hxx.tail $(GENHEADERPATH)$/tokens.hxx $(INCCOM)$/tokennames.inc $(MISC)$/tokenhash.gperf
     @@-$(RM) $@
