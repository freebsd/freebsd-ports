--- srcore/srmain.c.orig	Sun May 30 03:08:45 2004
+++ srcore/srmain.c	Sun May 30 03:09:28 2004
@@ -602,9 +602,10 @@
     sru_assert (config->key);
     if (strcmp (config->key, BRAILLE_DEVICE) == 0)
     {
+	gboolean rv;
 	sru_assert (config->newvalue && config->type == CFGT_STRING);
 	
-	gboolean rv = src_braille_set_device ((gchar*)config->newvalue);   
+	rv = src_braille_set_device ((gchar*)config->newvalue);   
 	if (!rv)
 	{
 	    sru_message ("SR: process config changed for braille: brl_device did not change!!!");
@@ -636,9 +637,10 @@
     }
     else if (strcmp (config->key, BRAILLE_TRANSLATION) == 0)
     {
+	gboolean rv;
     	sru_assert (config->type == CFGT_STRING && config->newvalue);
 	
-	gboolean rv = src_braille_set_translation_table ((gchar*)config->newvalue);
+	rv = src_braille_set_translation_table ((gchar*)config->newvalue);
 	
 	if (!rv)
 	{
