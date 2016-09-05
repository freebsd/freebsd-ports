--- src/qif.c.orig	2016-08-22 19:59:20 UTC
+++ src/qif.c
@@ -651,7 +651,7 @@ static gboolean qif_traite_champs_n ( st
     {
         if ( etat.get_qif_use_field_extract_method_payment )
         {
-            if ( strncmp ( imported_transaction->tiers, "VIR RECU", 8 ) == 0 );
+            if ( strncmp ( imported_transaction->tiers, "VIR RECU", 8 ) == 0 )
             {
                 gchar *tmp_str;
 
