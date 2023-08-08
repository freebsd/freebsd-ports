--- compose/asc-utils-l10n.c.orig	2023-02-10 19:54:13 UTC
+++ compose/asc-utils-l10n.c
@@ -390,11 +390,7 @@ asc_l10n_search_translations_qt (AscLocaleContext *ctx
 				locale = g_strdup (fname + strlen (qm_root) + 1);
 				g_strdelimit (locale, ".", '\0');
 				tmp = g_strstr_len (locale, -1, "/");
-				if (tmp != NULL) {
-					/* we have the ${hint}/${locale}.qm form */
-					locale = tmp + 1;
-				}
-				if (!asc_l10n_parse_file_qt (ctx, unit, locale, fname, error))
+				if (!asc_l10n_parse_file_qt (ctx, unit, tmp == NULL ? locale : tmp + 1, fname, error))
 					return FALSE;
 			}
 		}
