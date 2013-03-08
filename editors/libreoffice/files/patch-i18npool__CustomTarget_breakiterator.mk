--- ./i18npool/CustomTarget_breakiterator.mk.orig	2013-01-31 05:54:53.000000000 -0500
+++ ./i18npool/CustomTarget_breakiterator.mk	2013-02-22 15:26:45.000000000 -0500
@@ -120,7 +120,7 @@
 #   sed substitution...
 $(i18npool_BIDIR)/%.txt : \
 	$(SRCDIR)/i18npool/source/breakiterator/data/%.txt | $(i18npool_BIDIR)/.dir
-	sed -e ': dummy' \
+	$(SED) -e ': dummy' \
 		-e "s#\[:LineBreak =  Close_Punctuation:\]#\[& \[:LineBreak = Close_Parenthesis:\]\]#" \
 		$(if $(filter-out YES,$(ICU_RECLASSIFIED_CONDITIONAL_JAPANESE_STARTER)),\
 			-e '/\[:LineBreak =  Conditional_Japanese_Starter:\]/d' \
