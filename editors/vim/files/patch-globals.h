
$FreeBSD$

--- globals.h	2003/10/29 10:29:14	1.1
+++ globals.h	2003/10/29 10:29:51
@@ -1253,7 +1253,7 @@
 EXTERN char_u e_nowrtmsg[]	INIT(=N_("E37: No write since last change (add ! to override)"));
 EXTERN char_u e_null[]		INIT(=N_("E38: Null argument"));
 #ifdef FEAT_DIGRAPHS
-EXTERN char_u e_number[]	INIT(=N_("E39: Number expected"));
+EXTERN char_u e_numbe[]		INIT(=N_("E39: Number expected"));
 #endif
 #ifdef FEAT_QUICKFIX
 EXTERN char_u e_openerrf[]	INIT(=N_("E40: Can't open errorfile %s"));
