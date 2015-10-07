--- i18npool/CustomTarget_breakiterator.mk.orig	2015-08-22 06:41:35 UTC
+++ i18npool/CustomTarget_breakiterator.mk
@@ -98,7 +98,7 @@ $(i18npool_BIDIR)/%.brk : $(i18npool_BID
 #   sed substitution...
 $(i18npool_BIDIR)/%.txt : \
 	$(SRCDIR)/i18npool/source/breakiterator/data/%.txt | $(i18npool_BIDIR)/.dir
-	sed -e ': dummy' \
+	$(GNUSED) -e ': dummy' \
 		$(if $(ICU_RECLASSIFIED_CLOSE_PARENTHESIS),-e "s#\[:LineBreak =  Close_Punctuation:\]#\[& \[:LineBreak = Close_Parenthesis:\]\]#") \
 		$(if $(ICU_RECLASSIFIED_CONDITIONAL_JAPANESE_STARTER),,\
 			-e '/\[:LineBreak =  Conditional_Japanese_Starter:\]/d' \
