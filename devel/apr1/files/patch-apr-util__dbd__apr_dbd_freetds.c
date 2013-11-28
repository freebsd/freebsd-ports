# http://lists.freebsd.org/pipermail/freebsd-apache/2013-January/003020.html
# 
# From: "Mikhail T." <mi+thun@aldan.algebra.com>
#   I've made the FreeTDS-driver work again -- and submitted the patch to Apache:
#   https://issues.apache.org/bugzilla/show_bug.cgi?id=53666
===================================================================================
--- ./apr-util-1.5.3/dbd/apr_dbd_freetds.c.orig	2012-08-05 23:09:15.000000000 +0200
+++ ./apr-util-1.5.3/dbd/apr_dbd_freetds.c	2013-07-04 22:55:08.000000000 +0200
@@ -40,12 +40,12 @@
 #include <freetds/sybdb.h>
 #endif
 #ifdef HAVE_SYBDB_H
+#include <sybfront.h>
 #include <sybdb.h>
 #endif
 
 #include <stdio.h>
 #include <sys/types.h>
-#include <regex.h>
 
 /* This probably needs to change for different applications */
 #define MAX_COL_LEN 256
@@ -67,6 +67,7 @@
     apr_dbd_transaction_t *trans;
     apr_pool_t *pool;
     const char *params;
+    const char *lasterror;
     RETCODE err;
 };
 
@@ -80,20 +81,20 @@
 
 struct apr_dbd_row_t {
     apr_dbd_results_t *res;
-    BYTE buf[MAX_COL_LEN];
+    apr_pool_t *pool;
 };
 
 struct apr_dbd_prepared_t {
     int nargs;
-    regex_t **taint;
-    int *sz;
-    char *fmt;
+    int fmtlen;
+    const char *fmt, *label;
+    apr_dbd_type_e *types;
+    int offsets[];
 };
 
-#define dbd_freetds_is_success(x) (x == SUCCEED)
+const apr_dbd_driver_t apr_dbd_freetds_driver; /* Forward declaration */
 
-static int labelnum = 0; /* FIXME */
-static regex_t dbd_freetds_find_arg;
+#define dbd_freetds_is_success(x) (x == SUCCEED)
 
 /* execute a query that doesn't return a result set, mop up,
  * and return and APR-flavoured status
@@ -102,7 +103,11 @@
                             int want_results, int *nrows)
 {
     /* TBD */
-    RETCODE rv = dbcmd(proc, query);
+    RETCODE rv = dbcmd(proc,
+#ifndef TDS_STATIC_CAST /* if not compiling against FreeTDS, drop const :-( */
+	(char *)
+#endif
+	query);
     if (rv != SUCCEED) {
         return rv;
     }
@@ -143,6 +148,7 @@
      * Ignore seek
      */
 
+    sql->lasterror = NULL;
     sql->err = freetds_exec(sql->proc, query, 1, NULL);
     if (!dbd_freetds_is_success(sql->err)) {
         if (sql->trans) {
@@ -190,51 +196,38 @@
 #endif
     return (sql->err == SUCCEED) ? 0 : 1;
 }
-static const char *dbd_untaint(apr_pool_t *pool, regex_t *rx, const char *val)
-{
-    regmatch_t match[1];
-    if (rx == NULL) {
-        /* no untaint expression */
-        return val;
-    }
-    if (regexec(rx, val, 1, match, 0) == 0) {
-        return apr_pstrndup(pool, val+match[0].rm_so,
-                            match[0].rm_eo - match[0].rm_so);
-    }
-    return "";
-}
+
 static const char *dbd_statement(apr_pool_t *pool,
-                                 apr_dbd_prepared_t *stmt,
-                                 int nargs, const char **args)
+                                 const apr_dbd_prepared_t *stmt,
+                                 const char **args)
 {
     int i;
     int len;
-    const char *var;
     char *ret;
-    const char *p_in;
+    const char *p_in, *format;
     char *p_out;
-    char *q;
    
-    /* compute upper bound on length (since untaint shrinks) */
-    len  = strlen(stmt->fmt) +1;
-    for (i=0; i<nargs; ++i) {
-        len += strlen(args[i]) - 2;
+    len  = stmt->fmtlen;
+    for (i=0; i < stmt->nargs; ++i) {
+        len += strlen(args[i]);
+	switch (stmt->types[i]) {
+	case APR_DBD_TYPE_STRING: len += 2; break;	/* For the quotes */
+	default: break;/* Other types are all taken verbatim at the moment */
+	}
     }
-    i = 0;
     p_in = stmt->fmt;
     p_out = ret = apr_palloc(pool, len);
-    /* FIXME silly bug - this'll catch %%s */
-    while (q = strstr(p_in, "%s"), q != NULL) {
-        len = q-p_in;
-        strncpy(p_out, p_in, len);
-        p_in += len;
-        p_out += len;
-        var = dbd_untaint(pool, stmt->taint[i], args[i]);
-        len = strlen(var);
-        strncpy(p_out, var, len);
-        p_in += 2;
-        p_out += len;
-        ++i;
+    for (i = 0; i < stmt->nargs; i++) {
+        len = stmt->offsets[i];
+	switch (stmt->types[i]) {
+	case APR_DBD_TYPE_STRING:
+	    format = "%.*s'%s'";
+	    break;
+	default:
+	    format = "%.*s%s";
+	}
+	p_out += sprintf(p_out, format, len, p_in, args[i]);
+	p_in += (len + 1);
     }
     strcpy(p_out, p_in);
     return ret;
@@ -244,8 +237,7 @@
                                apr_dbd_prepared_t *statement,
                                int seek, const char **values)
 {
-    const char *query = dbd_statement(pool, statement,
-                                      statement->nargs, values);
+    const char *query = dbd_statement(pool, statement, values);
     return dbd_freetds_select(pool, sql, results, query, seek);
 }
 static int dbd_freetds_pvselect(apr_pool_t *pool, apr_dbd_t *sql,
@@ -273,8 +265,7 @@
                               int *nrows, apr_dbd_prepared_t *statement,
                               const char **values)
 {
-    const char *query = dbd_statement(pool, statement,
-                                      statement->nargs, values);
+    const char *query = dbd_statement(pool, statement, values);
     return dbd_freetds_query(sql, nrows, query);
 }
 static int dbd_freetds_pvquery(apr_pool_t *pool, apr_dbd_t *sql, int *nrows,
@@ -301,11 +292,13 @@
     RETCODE rv = 0;
     apr_dbd_row_t *row = *rowp;
     int sequential = ((rownum >= 0) && res->random) ? 0 : 1;
+    apr_dbd_t *sql = (void *)dbgetuserdata(res->proc);
 
     if (row == NULL) {
         row = apr_palloc(pool, sizeof(apr_dbd_row_t));
         *rowp = row;
         row->res = res;
+	row->pool = pool; /* For subsequent calls to get_entry */
     }
     /*
     else {
@@ -321,18 +314,37 @@
         rv = dbnextrow(res->proc);
     }
     else {
+	/* XXX dbgetrow() only works if DBBUFFER-option is set */
         rv = (rownum >= 0) ? dbgetrow(res->proc, rownum) : NO_MORE_ROWS;
     }
     switch (rv) {
     case SUCCEED: return 0;
     case REG_ROW: return 0;
     case NO_MORE_ROWS:
+	if (dbisopt(res->proc, DBBUFFER, NULL) || sequential) {
+	    sql->lasterror = apr_pstrcat(sql->pool,
+		"NO_MORE_ROWS (count: ", apr_itoa(sql->pool, DBCOUNT(res->proc)),
+		", first: ", apr_itoa(sql->pool, DBFIRSTROW(res->proc)),
+		", current: ", apr_itoa(sql->pool, DBCURROW(res->proc)),
+		", last: ", apr_itoa(sql->pool, DBLASTROW(res->proc)),
+		")", NULL);;
+	} else {
+	    sql->lasterror = "NO_MORE_ROWS (DBBUFFER option must be on "
+		"for dbgetrow() to work)";
+	}
         apr_pool_cleanup_run(res->pool, res->proc, clear_result);
         *rowp = NULL;
         return -1;
-    case FAIL: return 1;
-    case BUF_FULL: return 2; /* FIXME */
-    default: return 3;
+    case FAIL:
+	sql->lasterror = "FAIL";
+	return 1;
+    case BUF_FULL:
+	sql->lasterror = "BUF_FULL";
+	return 2; /* FIXME */
+    default:
+	sql->lasterror = apr_pstrcat(res->pool,
+	    "Unexpected error number ", apr_itoa(res->pool, rv), NULL);
+	return 3;
     }
 
     return 0;
@@ -340,24 +352,27 @@
 
 static const char *dbd_freetds_get_entry(const apr_dbd_row_t *row, int n)
 {
-    /* FIXME: support different data types */
-    /* this fails - bind gets some vars but not others
-    return (const char*)row->res->vars[n].data;
-     */
     DBPROCESS* proc = row->res->proc;
-    BYTE *ptr = dbdata(proc, n+1);
+    BYTE *ptr = dbdata(proc, n+1); /* XXX No error checking! */
     int t = dbcoltype(proc, n+1);
-    int l = dbcollen(proc, n+1);
+    int l = dbdatlen(proc, n+1);
+    if (l == -1)
+      return NULL;
     if (dbwillconvert(t, SYBCHAR)) {
-      dbconvert(proc, t, ptr, l, SYBCHAR, (BYTE *)row->buf, -1);
-      return (const char*)row->buf;
+      char *buf = apr_palloc(row->pool, l + 1);
+      dbconvert(proc, t, ptr, l, SYBCHAR, buf, -1);
+      return buf;
     }
     return (char*)ptr;
 }
 
 static const char *dbd_freetds_error(apr_dbd_t *sql, int n)
 {
-    /* XXX this doesn't seem to exist in the API ??? */
+    const char	*err = sql->lasterror;
+
+    sql->lasterror = NULL; /* Reset, so we stop appending */
+    if (err)
+	return err;
     return apr_psprintf(sql->pool, "Error %d", sql->err);
 }
 
@@ -367,6 +382,7 @@
         return sql->trans->errnum;
     }
     *nrows = 0;
+    sql->lasterror = NULL;
     sql->err = freetds_exec(sql->proc, query, 0, nrows);
 
     if (sql->err != SUCCEED) {
@@ -384,114 +400,39 @@
     return arg;
 }
 
-static apr_status_t freetds_regfree(void *rx)
-{
-    regfree((regex_t*)rx);
-    return APR_SUCCESS;
-}
-static int recurse_args(apr_pool_t *pool, int n, const char *query,
-                        apr_dbd_prepared_t *stmt, int offs)
-{
-
-    /* we only support %s arguments for now */
-    int ret;
-    char arg[256];
-    regmatch_t matches[3];
-    if (regexec(&dbd_freetds_find_arg, query, 3, matches, 0) != 0) {
-        /* No more args */
-        stmt->nargs = n;
-        stmt->taint = apr_palloc(pool, n*sizeof(regex_t*));
-        stmt->sz = apr_palloc(pool, n*sizeof(int));
-        ret = 0;
-    }
-    else {
-        int i;
-        int sz = 0;
-        int len = matches[1].rm_eo - matches[1].rm_so - 2;
-        if (len > 255) {
-            return 9999;
-        }
-
-        ret = recurse_args(pool, n+1, query+matches[0].rm_eo,
-                           stmt, offs+matches[0].rm_eo);
-
-        memmove(stmt->fmt + offs + matches[1].rm_so,
-                stmt->fmt + offs + matches[0].rm_eo-1,
-                strlen(stmt->fmt+offs+matches[0].rm_eo)+2);
-
-        /* compile untaint to a regex if found */
-        if (matches[1].rm_so == -1) {
-            stmt->taint[n] = NULL;
-        }
-        else {
-            strncpy(arg, query+matches[1].rm_so+1,
-                    matches[1].rm_eo - matches[1].rm_so - 2);
-            arg[matches[1].rm_eo - matches[1].rm_so - 2] = '\0';
-            stmt->taint[n] = apr_palloc(pool, sizeof(regex_t));
-            if (regcomp(stmt->taint[n], arg, REG_ICASE|REG_EXTENDED) != 0) {
-                ++ret;
-            }
-            else {
-                apr_pool_cleanup_register(pool, stmt->taint[n], freetds_regfree,
-                                          apr_pool_cleanup_null);
-            }
-        }
-
-        /* record length if specified */
-        for (i=matches[2].rm_so; i<matches[2].rm_eo; ++i) {
-            sz = 10*sz + (query[i]-'\0');
-        }
-    }
-    return ret;
-}
-
 static int dbd_freetds_prepare(apr_pool_t *pool, apr_dbd_t *sql,
                              const char *query, const char *label,
                              int nargs, int nvals, apr_dbd_type_e *types,
                              apr_dbd_prepared_t **statement)
 {
+    int	i;
+    const char *p, *op;
     apr_dbd_prepared_t *stmt;
 
-    if (label == NULL) {
-        label = apr_psprintf(pool, "%d", labelnum++);
+    if (!*statement &&
+	(*statement = apr_palloc(pool,
+	    sizeof(apr_dbd_prepared_t) + nargs*sizeof(int))) == NULL) {
+	return APR_EGENERAL;
     }
 
-    if (!*statement) {
-        *statement = apr_palloc(pool, sizeof(apr_dbd_prepared_t));
-    }
     stmt = *statement;
+    stmt->nargs = nargs;
+    stmt->fmt = query;
+    stmt->fmtlen = strlen(query) - nargs + 1;
+    stmt->types = types;
+    stmt->label = label; /* XXX Not used anywhere at the moment */
 
-#if 0
-    /* count args */
-    stmt->fmt = apr_pstrdup(pool, query);
-    stmt->fmt = recurse_args(pool, 0, query, stmt, stmt->fmt);
-
-    /* overestimate by a byte or two to simplify */
-    len = strlen("CREATE PROC apr.")
-            + strlen(label)
-            + stmt->nargs * strlen(" @arg1 varchar(len1),")
-            + strlen(" AS begin ")
-            + strlen(stmt->fmt)
-            + strlen(" end "); /* extra byte for terminator */
-
-    pquery = apr_pcalloc(pool, len);
-    sprintf(pquery, "CREATE PROC apr.%s", label);
-    for (i=0; i<stmt->nargs; ++i) {
-        sprintf(pquery+strlen(pquery), " @arg%d varchar(%d)", i, stmt->sz[i]);
-        if (i < stmt->nargs-1) {
-            pquery[strlen(pquery)] = ',';
-        }
+    /*
+     * Run through the query-template looking for the special character,
+     * which the dbd_prepare inserted into it on our behalf
+     */
+    for (i = 0, op = query; i < nargs; i++) {
+	p = strchr(op, apr_dbd_freetds_driver.pformat[0]);
+	stmt->offsets[i] = p - op;
+	op = p + 1;
     }
-    strcat(pquery, " AS BEGIN ");
-    strcat(pquery, stmt->fmt);
-    strcat(pquery, " END");
-
-    return (freetds_exec(sql->proc, pquery, 0, &i) == SUCCEED) ? 0 : 1;
-#else
-    stmt->fmt = apr_pstrdup(pool, query);
-    return recurse_args(pool, 0, query, stmt, 0);
-#endif
 
+    return APR_SUCCESS;
 }
 
 static int dbd_freetds_start_transaction(apr_pool_t *pool, apr_dbd_t *handle,
@@ -541,9 +482,9 @@
     DBPROCESS *process;
     LOGINREC *login;
     static const char *delims = " \r\n\t;|,";
-    char *ptr;
-    char *key;
-    char *value;
+    const char *ptr;
+    const char *key;
+    const char *value;
     int vlen;
     int klen;
     char *buf;
@@ -564,7 +505,7 @@
         }
         for (key = ptr-1; apr_isspace(*key); --key);
         klen = 0;
-        while (apr_isalpha(*key)) {
+        while (key >= params && apr_isalpha(*key)) {
             --key;
             ++klen;
         }
@@ -631,6 +572,7 @@
     sql->pool = pool;
     sql->proc = process;
     sql->params = params;
+    dbsetuserdata(process, (BYTE *)sql);
     return sql;
 }
 
@@ -686,24 +628,73 @@
 static apr_status_t freetds_term(void *dummy)
 {
     dbexit();
-    regfree(&dbd_freetds_find_arg);
     return APR_SUCCESS;
 }
+
+static int freetds_msg_handler(DBPROCESS *dbproc, DBINT msgno, int msgstate,
+                               int severity, char *msgtext, char *srvname,
+                               char *procname, int line)
+{
+    char	*value;
+    apr_dbd_t	*sql;
+
+    if (dbproc == NULL || (sql = (void *)dbgetuserdata(dbproc)) == NULL) {
+	/* Initial messages are not interesting */
+	return 0;
+    }
+
+    value = apr_psprintf(sql->pool, "%s: %s", srvname, msgtext);
+    if (procname && procname[0])
+	value = apr_pstrcat(sql->pool, value, " In procedure ",
+	    procname, NULL);
+    if (line)
+        value = apr_pstrcat(sql->pool, value,
+	    procname && procname[0] ? ", line " : " Line ",
+	    apr_itoa(sql->pool, line), NULL);
+
+    if (sql->lasterror)
+	sql->lasterror = apr_pstrcat(sql->pool, sql->lasterror, "\n", value, NULL);
+    else
+	sql->lasterror = value;
+
+    return 0;
+}
+
 static int freetds_err_handler(DBPROCESS *dbproc, int severity, int dberr,
                                int oserr, char *dberrstr, char *oserrstr)
 {
+    char	*value;
+    apr_dbd_t	*sql;
+
+    if (dbproc == NULL || (sql = (void *)dbgetuserdata(dbproc)) == NULL) {
+	fprintf(stderr, "%s\n", dberrstr);
+	return INT_CANCEL;
+    }
+    /*
+     * Do not append the useless "general error", if details
+     * are already recorded (by the msg_handler). Just return.
+     * XXX: this skipping currently only works with Sybase's OpenClient
+     * XXX: because FreeTDS implementation uses bogus dberr values:
+     * XXX: https://sourceforge.net/tracker/?func=detail&aid=3555777&group_id=33106&atid=407806
+     */
+    if (dberr == SYBESMSG && sql->lasterror)
+	return INT_CANCEL;
+
+    value = apr_psprintf(sql->pool, "%d: %s", dberr, dberrstr);
+    if (oserrstr) {
+	value = apr_pstrcat(sql->pool, ". (", oserrstr, ")", NULL);
+    }
+    if (sql->lasterror)
+	sql->lasterror = apr_pstrcat(sql->pool, sql->lasterror, "\n", value, NULL);
+    else
+	sql->lasterror = value;
     return INT_CANCEL; /* never exit */
 }
 static void dbd_freetds_init(apr_pool_t *pool)
 {
-    int rv = regcomp(&dbd_freetds_find_arg,
-                     "%(\\{[^}]*\\})?([0-9]*)[A-Za-z]", REG_EXTENDED);
-    if (rv != 0) {
-        char errmsg[256];
-        regerror(rv, &dbd_freetds_find_arg, errmsg, 256);
-        fprintf(stderr, "regcomp failed: %s\n", errmsg);
-    }
-    dbinit();
+    if (dbinit() == FAIL)
+	fprintf(stderr, "dbinit() failed\n");
+    dbmsghandle(freetds_msg_handler);
     dberrhandle(freetds_err_handler);
     apr_pool_cleanup_register(pool, NULL, freetds_term, apr_pool_cleanup_null);
 }
@@ -765,7 +756,11 @@
 #endif
 
 APU_MODULE_DECLARE_DATA const apr_dbd_driver_t apr_dbd_freetds_driver = {
+#ifndef TI_MODULE_NAME
     "freetds",
+#else
+    TI_MODULE_NAME,
+#endif
     dbd_freetds_init,
     dbd_freetds_native,
     dbd_freetds_open,
@@ -787,19 +782,14 @@
     dbd_freetds_pvselect,
     dbd_freetds_pquery,
     dbd_freetds_pselect,
-    /* this is only implemented to support httpd/2.2 standard usage,
-     * as in the original DBD implementation.  Everything else is NOTIMPL.
-     */
-#ifdef COMPILE_STUBS
     dbd_freetds_get_name,
     dbd_freetds_transaction_mode_get,
     dbd_freetds_transaction_mode_set,
-    "",
+    "\1", /* Would not occur in a real query... */
     dbd_freetds_pvbquery,
     dbd_freetds_pvbselect,
     dbd_freetds_pbquery,
     dbd_freetds_pbselect,
     dbd_freetds_datum_get
-#endif
 };
 #endif
