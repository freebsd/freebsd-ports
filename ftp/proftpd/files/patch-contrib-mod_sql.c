--- contrib/mod_sql.c.orig	Mon Dec 11 13:40:18 2006
+++ contrib/mod_sql.c	Thu Jan  4 14:31:13 2007
@@ -23,7 +23,7 @@
  * the resulting executable, without including the source code for OpenSSL in
  * the source distribution.
  *
- * $Id: mod_sql.c,v 1.117 2006/12/11 22:40:18 castaglia Exp $
+ * $Id: mod_sql.c,v 1.121 2007/01/03 18:24:35 castaglia Exp $
  */
 
 #include "conf.h"
@@ -104,8 +104,11 @@
 
 module sql_module;
 
-static char *_sql_where(cmd_rec *, int, ...);
 #define SQL_MAX_STMT_LEN	4096
+
+static char *sql_prepare_where(int, cmd_rec *, int, ...);
+#define SQL_PREPARE_WHERE_FL_NO_TAGS	0x00001
+
 static char *resolve_long_tag(cmd_rec *, char *);
 static int resolve_numeric_tag(cmd_rec *, char *);
 static char *resolve_short_tag(cmd_rec *, char);
@@ -752,10 +755,10 @@
   return mr ? (char *) mr->data : NULL;
 }
 
-static char *_sql_where(cmd_rec *cmd, int cnt, ...) {
+static char *sql_prepare_where(int flags, cmd_rec *cmd, int cnt, ...) {
   int i, flag;
   int curr_avail;
-  char *buf = "", *res, *tchar, *curr, *tmp;
+  char *buf = "", *res, *tchar;
   va_list dummy;
 
   res = pcalloc(cmd->tmp_pool, SQL_MAX_STMT_LEN);
@@ -774,31 +777,53 @@
   }
   va_end(dummy);
 
-  /* Process variables in WHERE clauses, except any "%{num}" references. */
-  curr = res;
-  curr_avail = SQL_MAX_STMT_LEN;
-  for (tmp = buf; *tmp; ) {
-    char *str;
-    modret_t *mr;
+  if (!(flags & SQL_PREPARE_WHERE_FL_NO_TAGS)) {
+    char *curr, *tmp;
 
-    if (*tmp == '%') {
-      char *tag = NULL;
+    /* Process variables in WHERE clauses, except any "%{num}" references. */
+    curr = res;
+    curr_avail = SQL_MAX_STMT_LEN;
+
+    for (tmp = buf; *tmp; ) {
+      char *str;
+      modret_t *mr;
 
-      if (*(++tmp) == '{') {
-        char *query;
+      if (*tmp == '%') {
+        char *tag = NULL;
 
-        if (*tmp != '\0')
-          query = ++tmp;
+        if (*(++tmp) == '{') {
+          char *query;
 
-        while (*tmp && *tmp != '}')
-          tmp++;
+          if (*tmp != '\0')
+            query = ++tmp;
+
+          while (*tmp && *tmp != '}')
+            tmp++;
+
+          tag = pstrndup(cmd->tmp_pool, query, (tmp - query));
+          if (tag) {
+            str = resolve_long_tag(cmd, tag);
+            if (!str)
+              str = pstrdup(cmd->tmp_pool, "");
+
+            mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 2, "default",
+              str), "sql_escapestring");
+            if (check_response(mr) < 0)
+              return NULL;
 
-        tag = pstrndup(cmd->tmp_pool, query, (tmp - query));
-        if (tag) {
-          str = resolve_long_tag(cmd, tag);
-          if (!str)
-            str = pstrdup(cmd->tmp_pool, "");
+            sstrcat(curr, mr->data, curr_avail);
+            curr += strlen(mr->data);
+            curr_avail -= strlen(mr->data);
+
+            if (*tmp != '\0')
+              tmp++;
+
+          } else {
+            return NULL;
+          }
 
+        } else {
+          str = resolve_short_tag(cmd, *tmp);
           mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 2, "default",
             str), "sql_escapestring");
           if (check_response(mr) < 0)
@@ -810,32 +835,18 @@
 
           if (*tmp != '\0')
             tmp++;
-
-        } else {
-          return NULL;
         }
 
       } else {
-        str = resolve_short_tag(cmd, *tmp);
-        mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 2, "default",
-          str), "sql_escapestring");
-        if (check_response(mr) < 0)
-          return NULL;
-
-        sstrcat(curr, mr->data, curr_avail);
-        curr += strlen(mr->data);
-        curr_avail -= strlen(mr->data);
-
-        if (*tmp != '\0')
-          tmp++;
+        *curr++ = *tmp++;
+        curr_avail--;
       }
-
-    } else {
-      *curr++ = *tmp++;
-      curr_avail--;
     }
+    *curr++ = '\0';
+
+  } else {
+    res = buf;
   }
-  *curr++ = '\0';
 
   return res;
 }
@@ -1212,7 +1223,7 @@
   }
 
   if (!cmap.usercustom) { 
-    where = _sql_where(cmd, 2, usrwhere, cmap.userwhere);
+    where = sql_prepare_where(0, cmd, 2, usrwhere, cmap.userwhere, NULL);
 
     mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 5, "default",
       cmap.usrtable, cmap.usrfields, where, "1"), "sql_select");
@@ -1438,7 +1449,7 @@
       return NULL;
     }
 
-    where = _sql_where(cmd, 2, grpwhere, cmap.groupwhere);
+    where = sql_prepare_where(0, cmd, 2, grpwhere, cmap.groupwhere, NULL);
 
     mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 5, "default",
       cmap.grptable, cmap.grpfield, where, "1"), "sql_select");
@@ -1456,7 +1467,7 @@
 
   grpwhere = pstrcat(cmd->tmp_pool, cmap.grpfield, " = '", groupname, "'",
     NULL);
-  where = _sql_where(cmd, 2, grpwhere, cmap.groupwhere);
+  where = sql_prepare_where(0, cmd, 2, grpwhere, cmap.groupwhere, NULL);
   
   mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 4, "default",
     cmap.grptable, cmap.grpfields, where), "sql_select");
@@ -1530,7 +1541,7 @@
 
   usrwhere = pstrcat(cmd->tmp_pool, cmap.usrfield, " = '", _sql_realuser(cmd),
     "'", NULL);
-  where = _sql_where(cmd, 2, usrwhere, cmap.userwhere);
+  where = sql_prepare_where(0, cmd, 2, usrwhere, cmap.userwhere, NULL);
 
   mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 4, "default", cmap.usrtable,
     query, where), "sql_update");
@@ -1606,7 +1617,8 @@
       cmap.grpmembersfield, " = '", username, "'", NULL);
   }
 
-  where = _sql_where(cmd, 2, grpwhere, cmap.groupwhere);
+  where = sql_prepare_where(SQL_PREPARE_WHERE_FL_NO_TAGS, cmd, 2, grpwhere,
+    sql_prepare_where(0, cmd, 1, cmap.groupwhere, NULL), NULL);
   
   mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 4, "default",
     cmap.grptable, cmap.grpfields, where), "sql_select");
@@ -1746,7 +1758,7 @@
 static char *resolve_short_tag(cmd_rec *cmd, char tag) {
   char arg[256] = {'\0'}, *argp;
 
-  switch(tag) {
+  switch (tag) {
   case 'A': {
       char *pass;
 
@@ -2915,7 +2927,7 @@
   /* single select or not? */
   if (SQL_FASTUSERS) {
     /* retrieve our list of passwds */
-    where = _sql_where(cmd, 1, cmap.userwhere);
+    where = sql_prepare_where(0, cmd, 1, cmap.userwhere, NULL);
 
     mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 4, "default",
       cmap.usrtable, cmap.usrfields, where), "sql_select");
@@ -2978,7 +2990,7 @@
     } 
   } else {
     /* retrieve our list of passwds */
-    where = _sql_where(cmd, 1, cmap.userwhere);
+    where = sql_prepare_where(0, cmd, 1, cmap.userwhere, NULL);
     
     mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 4, "default",
       cmap.usrtable, cmap.usrfield, where), "sql_select");
@@ -3086,7 +3098,7 @@
 
   if (SQL_FASTGROUPS) {
     /* retrieve our list of groups */
-    where = _sql_where(cmd, 1, cmap.groupwhere);
+    where = sql_prepare_where(0, cmd, 1, cmap.groupwhere, NULL);
     
     mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 6, "default",
       cmap.grptable, cmap.grpfields, where, NULL), "sql_select");
@@ -3119,9 +3131,15 @@
     }
 
   } else {
-    /* retrieve our list of groups */
-    where = _sql_where(cmd, 1, cmap.groupwhere);
-    
+    /* Retrieve our list of groups. */
+    if (cmap.groupwhere &&
+        strlen(cmap.groupwhere) > 0) {
+      where = sql_prepare_where(0, cmd, 1, cmap.groupwhere, NULL);
+
+    } else {
+      where = NULL;
+    }
+ 
     mr = _sql_dispatch(_sql_make_cmd(cmd->tmp_pool, 6, "default",
       cmap.grptable, cmap.grpfield, where, NULL, "DISTINCT"), "sql_select");
     if (check_response(mr) < 0)
@@ -3593,7 +3611,7 @@
 
   usrwhere = pstrcat(cmd->tmp_pool, cmap.usrfield, " = '", _sql_realuser(cmd),
     "'", NULL);
-  where = _sql_where(cmd, 2, usrwhere, cmap.userwhere);
+  where = sql_prepare_where(0, cmd, 2, usrwhere, cmap.userwhere, NULL);
   
   query = pstrcat(cmd->tmp_pool, cmap.sql_fstor, ", ",
 		  cmap.sql_fretr, ", ", cmap.sql_bstor, ", ",
@@ -3627,7 +3645,7 @@
 
   usrwhere = pstrcat(cmd->tmp_pool, cmap.usrfield, " = '", _sql_realuser(cmd),
     "'", NULL);
-  where = _sql_where(cmd, 2, usrwhere, cmap.userwhere);
+  where = sql_prepare_where(0, cmd, 2, usrwhere, cmap.userwhere, NULL);
   
   query = pstrcat(cmd->tmp_pool, cmap.sql_frate, ", ",
 		  cmap.sql_fcred, ", ", cmap.sql_brate, ", ",
