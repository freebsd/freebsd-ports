--- helpcontent2/CustomTarget_html.mk.orig	2025-11-20 20:45:20 UTC
+++ helpcontent2/CustomTarget_html.mk
@@ -87,7 +87,7 @@ $(gb_CustomTarget_workdir)/helpcontent2/help3xsl/langu
 
 # set of installed languages - has to be language independent
 $(gb_CustomTarget_workdir)/helpcontent2/help3xsl/languages.js : $(SRCDIR)/helpcontent2/CustomTarget_html.mk
-	$(file >$@,var languagesSet = new Set([$(subst $(WHITESPACE),$(COMMA) ,$(patsubst %,'%',$(gb_HELP_LANGS)))]);)
+	$(file >$@,var languagesSet = new Set([$(subst $(WHITESPACE),$(COMMA) ,$(patsubst %,'%',$(ALL_LANGS)))]);)
 
 # names of the languages - has to be translated, ie. per language
 $(gb_CustomTarget_workdir)/helpcontent2/help3xsl/%/langnames.js : \
