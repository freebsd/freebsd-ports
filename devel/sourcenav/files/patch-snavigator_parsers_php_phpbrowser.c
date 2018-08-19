--- snavigator/parsers/php/phpbrowser.c.orig	2010-02-02 12:29:53 UTC
+++ snavigator/parsers/php/phpbrowser.c
@@ -5878,7 +5878,7 @@ YY_RULE_SETUP
     free_head_token(); /* const keyword */
 
     if ( !current_class )
-        return;
+        return 0;
 
     result = sn_insert_symbol(SN_ENUM_CONST_DEF,
         current_class,
