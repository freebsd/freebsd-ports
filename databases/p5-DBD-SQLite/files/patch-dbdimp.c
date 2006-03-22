$FreeBSD$

--- dbdimp.c.orig	Wed Mar 22 15:21:16 2006
+++ dbdimp.c	Wed Mar 22 15:21:38 2006
@@ -260,7 +260,7 @@ sqlite_st_prepare (SV *sth, imp_sth_t *i
     imp_sth->retval = SQLITE_OK;
     imp_sth->params = newAV();
 
-    if ((retval = sqlite3_prepare(imp_dbh->db, statement, 0, &(imp_sth->stmt), &extra))
+    if ((retval = sqlite3_prepare(imp_dbh->db, statement, -1, &(imp_sth->stmt), &extra))
         != SQLITE_OK)
     {
         if (imp_sth->stmt) {
@@ -320,7 +320,7 @@ sqlite_st_execute (SV *sth, imp_sth_t *i
         psv = hv_fetch((HV*)SvRV(sth), "Statement", 9, 0);
         statement = (psv && SvOK(*psv)) ? SvPV_nolen(*psv) : "";
         sqlite_trace(3, "re-prepare statement %s", statement);
-        if ((retval = sqlite3_prepare(imp_dbh->db, statement, 0, &(imp_sth->stmt), &extra))
+        if ((retval = sqlite3_prepare(imp_dbh->db, statement, -1, &(imp_sth->stmt), &extra))
             != SQLITE_OK)
         {
             if (imp_sth->stmt) {
