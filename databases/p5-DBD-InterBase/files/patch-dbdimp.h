--- dbdimp.h.old	Tue Feb 24 10:49:01 2004
+++ dbdimp.h	Mon Mar 14 20:22:52 2005
@@ -252,6 +252,7 @@
 #define dbd_init            ib_init
 #define dbd_discon_all      ib_discon_all
 #define dbd_db_login        ib_db_login
+#define dbd_db_login6       ib_db_login6
 #define dbd_db_do           ib_db_do
 #define dbd_db_commit       ib_db_commit
 #define dbd_db_rollback     ib_db_rollback
@@ -283,6 +284,7 @@
 int ib_commit_transaction  (SV *h, imp_dbh_t *imp_dbh);
 int ib_rollback_transaction(SV *h, imp_dbh_t *imp_dbh);
 long ib_rows(SV *xxh, isc_stmt_handle *h_stmt, char count_type);
+void ib_cleanup_st_prepare (imp_sth_t *imp_sth);
 
 SV* dbd_db_quote(SV* dbh, SV* str, SV* type);
 
