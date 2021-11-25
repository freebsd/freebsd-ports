--- helpcontent2/CustomTarget_html.mk.orig	2021-10-29 17:06:25 UTC
+++ helpcontent2/CustomTarget_html.mk
@@ -116,7 +116,7 @@ $(call gb_CustomTarget_get_workdir,helpcontent2/help3x
 		$(SRCDIR)/helpcontent2/CustomTarget_html.mk
 	( \
 		printf 'var languagesSet = new Set([' ; \
-		for lang in $(gb_HELP_LANGS) ; do printf '%s' "'$$lang', " ; done | sed 's/, $$//' ; \
+		for lang in $(ALL_LANGS) ; do printf '%s' "'$$lang', " ; done | sed 's/, $$//' ; \
 		printf ']);\n' \
 	) > $@
 
