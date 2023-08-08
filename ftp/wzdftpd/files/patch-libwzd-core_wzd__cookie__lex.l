--- libwzd-core/wzd_cookie_lex.l.orig	2023-02-11 11:26:34 UTC
+++ libwzd-core/wzd_cookie_lex.l
@@ -1731,7 +1731,7 @@ out_err(LEVEL_HIGH,"char: %d [%c]\n", c, c);
       {
         /* check FLAG_SITEOP for self */
         if (me && me->flags && strchr(me->flags,FLAG_SITEOP))
-          snprintf(internalbuffer,IBUFSIZE,"%lu",current_context->pid_child);
+          snprintf(internalbuffer,IBUFSIZE,"%lu",(unsigned long)current_context->pid_child);
         else
           snprintf(internalbuffer,IBUFSIZE,"some id");
       }
