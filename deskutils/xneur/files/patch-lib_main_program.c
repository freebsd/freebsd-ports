--- lib/main/program.c.orig	2020-03-26 11:56:18 UTC
+++ lib/main/program.c
@@ -445,7 +445,7 @@ static void program_process_input(struct _program *p)
 			#ifdef WITH_ASPELL
 					if (xconfig->handle->has_spell_checker[lang])
 					{
-						loKg_message(DEBUG, _("      %s aspell dictionary loaded"), lang_name);
+						log_message(DEBUG, _("      %s aspell dictionary loaded"), lang_name);
 					}
 					else
 					{
