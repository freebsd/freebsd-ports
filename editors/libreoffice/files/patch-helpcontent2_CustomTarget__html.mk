--- helpcontent2/CustomTarget_html.mk.orig	2022-12-22 00:14:09 UTC
+++ helpcontent2/CustomTarget_html.mk
@@ -115,7 +115,7 @@ $(call gb_CustomTarget_get_workdir,helpcontent2/help3x
 # set of installed languages - has to be language independent
 $(call gb_CustomTarget_get_workdir,helpcontent2/help3xsl)/languages.js : \
         $(SRCDIR)/helpcontent2/CustomTarget_html.mk
-	printf 'var languagesSet = new Set([%s]);\n' "$(subst $(WHITESPACE),$(COMMA) ,$(patsubst %,'%',$(gb_HELP_LANGS)))" > $@
+	printf 'var languagesSet = new Set([%s]);\n' "$(subst $(WHITESPACE),$(COMMA) ,$(patsubst %,'%',$(ALL_LANGS)))" > $@
 
 define html_gen_langnames_js_dep
 $(call gb_CustomTarget_get_workdir,helpcontent2/help3xsl)/$(1)/langnames.js : \
