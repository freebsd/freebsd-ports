--- src/bet_data.c.orig	2014-02-01 14:51:11.000000000 +0100
+++ src/bet_data.c	2014-03-19 21:28:28.000000000 +0100
@@ -443,7 +443,7 @@
     {
         if ( sub_div_nb == 0 )
             return_val = TRUE;
-        else if ( sub_div_nb > 0 );
+        else if ( sub_div_nb > 0 )
         {
             sub_key = utils_str_itoa ( sub_div_nb );
             if ( g_hash_table_lookup ( shd -> sub_div_list, sub_key ) )
