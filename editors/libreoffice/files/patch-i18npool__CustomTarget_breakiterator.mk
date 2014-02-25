--- i18npool/CustomTarget_breakiterator.mk.orig	2013-12-11 01:11:21.000000000 +0900
+++ i18npool/CustomTarget_breakiterator.mk	2014-01-29 16:54:14.000000000 +0900
@@ -77,7 +77,7 @@
 #   sed substitution...
 $(i18npool_BIDIR)/%.txt : \
 	$(SRCDIR)/i18npool/source/breakiterator/data/%.txt | $(i18npool_BIDIR)/.dir
-	sed -e ': dummy' \
+	$(SED) -e ': dummy' \
 		$(if $(filter YES,$(ICU_RECLASSIFIED_CLOSE_PARENTHESIS)),-e "s#\[:LineBreak =  Close_Punctuation:\]#\[& \[:LineBreak = Close_Parenthesis:\]\]#") \
 		$(if $(filter-out YES,$(ICU_RECLASSIFIED_CONDITIONAL_JAPANESE_STARTER)),\
 			-e '/\[:LineBreak =  Conditional_Japanese_Starter:\]/d' \
