--- imsp/abook.c.orig	Mon Dec 15 15:52:51 2003
+++ imsp/abook.c	Mon Dec 15 15:58:41 2003
@@ -68,8 +68,9 @@
 /* generate the database name for an address book
  *  returns -1 for invalid name, otherwise returns length of owner name
  */
-static int abook_dbname(dbname, name)
+static int abook_dbname(dbname, name, dbnamelen)
     char *dbname, *name;
+    size_t dbnamelen;
 {
     char *split;
     int len = strlen(name), ownerlen;
@@ -86,7 +87,9 @@
 	ownerlen = split - name;
     }
 
-    sprintf(dbname, abookdb, ownerlen, name, name);
+    if (snprintf(dbname, dbnamelen, abookdb, ownerlen, name,
+      name) >= dbnamelen)
+	    return (-1);
 
     return (ownerlen);
 }
@@ -104,7 +107,7 @@
     long mask = 0;
 
     /* look up the database */
-    len = abook_dbname(dbname, name);
+    len = abook_dbname(dbname, name, sizeof(dbname));
     if (len < 0) return (0);
     
     /* get the ACL */
@@ -161,7 +164,7 @@
 	while (dot >= cname && *dot != '.') --dot;
 	if (dot >= cname) *dot = '\0';
 	sdb_get(abooks, cname, SDB_ICASE, pacl);
-	abook_dbname(dbname, cname);
+	abook_dbname(dbname, cname, sizeof(dbname));
 	exists = sdb_check(dbname);
 	if (exists == 0) mask = abook_rights(id, cname, *pacl);
         if (dot >= cname) --dot;
@@ -212,7 +215,7 @@
     state->kv = NULL;
     *count = 0;
     *freedata = 0;
-    if (abook_dbname(dbname, name) < 0) return (NULL);
+    if (abook_dbname(dbname, name, sizeof(dbname)) < 0) return (NULL);
 
 #ifdef HAVE_LDAP
     if (abook_usesldap(id, name)) {
@@ -348,7 +351,7 @@
     }
 #endif
 
-    if (abook_dbname(dbname, name) < 0) return (AB_FAIL);
+    if (abook_dbname(dbname, name, sizeof(dbname)) < 0) return (AB_FAIL);
 
     /* start match */
     if (!fcount) {
@@ -481,7 +484,8 @@
     int ownerlen, result = 0;
 
     /* find abook, and make sure it doesn't exist */
-    if ((ownerlen = abook_dbname(dbname, name)) < 0) return (AB_FAIL);
+    if ((ownerlen = abook_dbname(dbname, name, sizeof(dbname))) < 0)
+	return (AB_FAIL);
     if (sdb_check(dbname) == 0) return (AB_EXIST);
 
 #if 0
@@ -562,7 +566,7 @@
     char *sep, *value;
 
     /* find abook, and make sure it exists */
-    if ((ownerlen = abook_dbname(dbname, name)) < 0) {
+    if ((ownerlen = abook_dbname(dbname, name, sizeof(dbname))) < 0) {
 	return (AB_FAIL);
     }
     if (ownerlen == strlen(name) && auth_level(id) != AUTH_ADMIN) {
@@ -630,8 +634,8 @@
 
     /* make sure names are valid */
     if (!strcasecmp(name, newname) ||
-	(osrclen = abook_dbname(dbsrc, name)) < 0 ||
-	(odstlen = abook_dbname(dbdst, newname)) < 0) {
+	(osrclen = abook_dbname(dbsrc, name, sizeof(dbsrc))) < 0 ||
+	(odstlen = abook_dbname(dbdst, newname, sizeof(dbdst))) < 0) {
 	return (AB_FAIL);
     }
     if (sdb_check(dbsrc) < 0) return (AB_NOEXIST);
@@ -734,7 +738,8 @@
     int i, result, ownerlen, maxfieldlen, len;
     long delta;
 
-    if ((ownerlen = abook_dbname(dbname, name)) < 0) return (AB_FAIL);
+    if ((ownerlen = abook_dbname(dbname, name, sizeof(dbname))) < 0)
+	return (AB_FAIL);
     sprintf(uname, "%.*s", ownerlen, name);
 
     /* check for invalid characters in alias or field */
@@ -844,7 +849,8 @@
 	return (AB_PERM);
     }
 
-    if ((ownerlen = abook_dbname(dbname, name)) < 0) return (AB_FAIL);
+    if ((ownerlen = abook_dbname(dbname, name, sizeof(dbname))) < 0)
+	return (AB_FAIL);
 
     /* check for invalid characters in alias */
     for (scan = alias; *scan && *scan != '*' && *scan != '%'; ++scan);
@@ -910,7 +916,8 @@
     }
 
     /* make sure db exists */
-    if ((ownerlen = abook_dbname(dbname, name)) < 0) return (AB_FAIL);
+    if ((ownerlen = abook_dbname(dbname, name, sizeof(dbname))) < 0)
+	return (AB_FAIL);
     if (sdb_check(dbname) < 0) return (AB_NOEXIST);
 
     /* lock acl db */
@@ -977,7 +984,7 @@
     char *acl;
     
     /* look up the database */
-    if (abook_dbname(dbname, name) < 0) return (NULL);
+    if (abook_dbname(dbname, name, sizeof(dbname)) < 0) return (NULL);
 
     /* make sure db exists */
     if (sdb_check(dbname) < 0) return (NULL);
