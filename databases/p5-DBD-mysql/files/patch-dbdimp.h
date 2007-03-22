--- dbdimp.h.orig	Thu Mar 22 10:28:38 2007
+++ dbdimp.h	Thu Mar 22 10:28:54 2007
@@ -282,11 +282,7 @@
 #endif
 
 #include <dbd_xsh.h>
-#if MYSQL_VERSION_ID >= SQL_STATE_VERSION
 void    do_error (SV* h, int rc, const char *what, const char *sqlstate);
-#else
-void    do_error (SV* h, int rc, const char *what);
-#endif
 SV	*dbd_db_fieldlist (MYSQL_RES* res);
 
 void    dbd_preparse (imp_sth_t *imp_sth, SV *statement);
