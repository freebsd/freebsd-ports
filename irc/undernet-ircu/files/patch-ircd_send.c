
$FreeBSD$

--- ircd/send.c.orig
+++ ircd/send.c
@@ -697,7 +697,7 @@
    * this is ok...
    */
   vd.vd_format = pattern;
-  vd.vd_args = vl;
+  va_copy(vd.vd_args, vl);
   mb = msgq_make(0, ":%s " MSG_NOTICE " * :*** Notice -- %v", cli_name(&me),
 		 &vd);
 
