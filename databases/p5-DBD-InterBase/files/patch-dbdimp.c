--- dbdimp.c.old	Wed Feb 25 07:38:03 2004
+++ dbdimp.c	Mon Mar 14 20:23:19 2005
@@ -1002,9 +1002,6 @@
 {
     D_imp_dbh_from_sth;
     ISC_STATUS status[ISC_STATUS_LENGTH];
-    char       stmt_info[1], count_info[1];
-    char       info_buffer[20], count_buffer[33];
-    char       *p;
     int        result = -2;
     int        row_count = 0;
 
@@ -1543,7 +1540,10 @@
                                   blob_info_buffer);
 
                     if (ib_error_check(sth, status))
+                    {
+                        isc_cancel_blob(status, &blob_handle);
                         return FALSE;
+                    }
 
                     /* Get the information out of the info buffer. */
                     for (p = blob_info_buffer; *p != isc_info_end; )
@@ -1590,7 +1590,7 @@
                     if ((DBIc_LongReadLen(imp_sth) < (unsigned long) total_length) &&
                         (! DBIc_is(imp_dbh, DBIcf_LongTruncOk)))
                     {
-                        isc_cancel_blob(status, &blob_handle);
+                        isc_close_blob(status, &blob_handle);
                         do_error(sth, 1, "Not enough LongReadLen buffer.");
                         return FALSE;
                         break;
@@ -1603,7 +1603,7 @@
                         sv_setpvn(sv, "** Blob exceeds maximum safe length **", 38);
 
                         /* I deliberately don't set FAILURE based on this. */
-                        isc_cancel_blob(status, &blob_handle);
+                        isc_close_blob(status, &blob_handle);
                         if (ib_error_check(sth, status))
                             return FALSE;
                         break;
@@ -1620,12 +1620,15 @@
                                                     (short) BLOB_SEGMENT,
                                                     blob_segment_buffer);
 
+                        if (status[1] == isc_segstr_eof)
+                            break;
+
                         if (status[1] != isc_segment)
                             if (ib_error_check(sth, status))
+                            {
+                                isc_cancel_blob(status, &blob_handle);
                                 return FALSE;
-
-                        if (status[1] == isc_segstr_eof)
-                            break;
+                            }
 
                         if (seg_length > DBIc_LongReadLen(imp_sth))
                              break;
@@ -1744,11 +1747,7 @@
     DBI_TRACE(2, (DBILOGFP, "dbd_st_destroy\n"));
 
     /* freeing cursor name */
-    if (imp_sth->cursor_name != NULL)
-    {
-        safefree(imp_sth->cursor_name);
-        imp_sth->cursor_name = NULL;
-    }
+    FREE_SETNULL(imp_sth->cursor_name);
 
     /* freeing in_sqlda */
     if (imp_sth->in_sqlda)
@@ -1955,31 +1954,6 @@
 
     DBI_TRACE(2, (DBILOGFP, "dbd_st_STORE - %s\n", key));
 
-    if ((kl == 13) && (strcmp(key, "ib_cursorname") == 0))
-    {
-        if (DBIc_ACTIVE(imp_sth))
-        {
-            do_error(sth, 1, "Can't modify active statement cursor name.");
-            return FALSE;
-        }
-        else
-        {
-            STRLEN  vl;
-            char *value = SvPV(valuesv, vl);
-
-            if (imp_sth->cursor_name != NULL)
-            {
-                safefree(imp_sth->cursor_name);
-                imp_sth->cursor_name = NULL;
-            }
-            imp_sth->cursor_name = (char *)safemalloc(vl + 1);
-
-            if (imp_sth->cursor_name != NULL)
-                strcpy(imp_sth->cursor_name, value);
-            else
-                return FALSE;
-        }
-    }
     return FALSE;
 }
 
@@ -2185,7 +2159,7 @@
             DBI_TRACE(1, (DBILOGFP, "ib_fill_isqlda: SQL_VARYING\n"));
         {
             char buf[25]; /* long long can have max 20 chars. */
-            char *tmp;
+            char *tmp = NULL;
             if (ivar->sqldata == (char *) NULL)
             {
                 if ((ivar->sqldata = (char *)safemalloc(
@@ -2204,7 +2178,7 @@
                 tmp = buf;
                 len = sprintf(tmp, "%ld", SvNV(value));
             }
-            else if (SvPOK(value)) {
+            else if (SvPOK(value) || (SvTYPE(value) == SVt_PVMG)) {
                 len = SvCUR(value);
                 tmp = SvPV_nolen(value);
             }
@@ -2249,7 +2223,6 @@
                 {
                     do_error(sth, 2, "Cannot allocate buffer for TEXT input parameter \n");
                     retval = FALSE;
-                    safefree(tmp);
                     break;
                 }
             }
@@ -2261,7 +2234,7 @@
                 tmp = buf;
                 len = sprintf(tmp, "%ld", SvNV(value));
             }
-            else if (SvPOK(value)) {
+            else if (SvPOK(value) || (SvTYPE(value) == SVt_PVMG)) {
                 len = SvCUR(value);
                 tmp = SvPV_nolen(value);
             }
@@ -2579,6 +2552,12 @@
 
                 ivar->sqltype = SQL_TEXT | (ivar->sqltype & 1);
 
+                /* prevent overflow */
+                if (len > 100) {
+                    do_error(sth, 2, "DATE input parameter too long, but will try...\n");
+                    len = 100;
+                }
+
                 /* workaround for date problem (bug #429820) */
                 ivar->sqlsubtype = 0x77; /* (0x77 is a random value) */
 
@@ -2696,8 +2675,18 @@
         case SQL_BLOB:
             DBI_TRACE(1, (DBILOGFP, "ib_fill_isqlda: SQL_BLOB\n"));
 
-            /* we have an extra function for this */
-            retval = ib_blob_write(sth, imp_sth, ivar, value);
+            /* SELECT's can't have a blob as in_sqlda. */
+            if ((imp_sth->type == isc_info_sql_stmt_select) ||
+                (imp_sth->type == isc_info_sql_stmt_select_for_upd))
+            {
+                do_error(sth, 2, "BLOB as an input param for SELECT is not allowed.\n");
+                retval = FALSE;
+                break;
+            }
+            else
+                /* we have an extra function for this */
+                retval = ib_blob_write(sth, imp_sth, ivar, value);
+
             break;
 
         /**********************************************************************/
