--- dbdimp.c.orig	2008-01-08 06:02:45 UTC
+++ dbdimp.c
@@ -113,7 +113,7 @@ void do_error(SV *h, int rc, char *what)
 
     if (DBIc_TRACE_LEVEL(imp_xxh) >= 2)
         PerlIO_printf(DBIc_LOGPIO(imp_xxh), "%s error %d recorded: %s\n", 
-            what, rc, SvPV(errstr,na));
+            what, rc, SvPV(errstr,PL_na));
 }
 
 #define CALC_AVAILABLE(buff) sizeof(buff) - strlen(buff) - 1
@@ -693,7 +693,7 @@ SV *dbd_db_FETCH_attrib(SV *dbh, imp_dbh_t *imp_dbh, S
         return Nullsv;
     else
     {
-        if ((result == &sv_yes) || (result == &sv_no))
+        if ((result == &PL_sv_yes) || (result == &PL_sv_no))
             return result;
         else
             return sv_2mortal(result);
@@ -1991,8 +1991,8 @@ int dbd_discon_all(SV *drh, imp_drh_t *imp_drh)
         DBIh_EVENT2(drh, ERROR_event, DBIc_ERR(imp_drh), DBIc_ERRSTR(imp_drh));
         return FALSE;
     }
-    if (perl_destruct_level)
-        perl_destruct_level = 0;
+    if (PL_perl_destruct_level)
+        PL_perl_destruct_level = 0;
     return FALSE;
 }
 
