--- cdb.c.orig	Sat Nov 16 01:01:11 2002
+++ cdb.c	Sat Nov 16 01:20:25 2002
@@ -140,11 +140,11 @@
    char *k;
    struct cdb *cdb;
    uint32 pos;
-   unsigned int len;
+   long len;
 
    Get_CDB(obj, cdb);
    Check_FD(cdb);
-   k = str2cstr(key, &len);
+   k = rb_str2cstr(key, &len);
    switch (cdb_find(cdb, k, len)) {
       case 1:
          return _cdb_read(cdb, cdb_datapos(cdb), cdb_datalen(cdb));
@@ -178,13 +178,13 @@
    char *k;
    VALUE key;
    struct cdb *cdb;
-   unsigned int len;
+   long len;
 
    Get_CDB(obj, cdb);
    Check_FD(cdb);
 
    if (rb_scan_args(argc, argv, "01", &key) == 1) {
-      k = str2cstr(key, &len);
+      k = rb_str2cstr(key, &len);
       cdb_findstart(cdb);
 
       while ((ret = cdb_findnext(cdb, k, len)) == 1)
@@ -330,12 +330,12 @@
 {
    struct cdb_make *cdb;
    char *k, *d;
-   unsigned int klen, dlen;
+   long klen, dlen;
    
    Get_CDBMake(obj, cdb);
    Check_FD(cdb);
-   k = str2cstr(key, &klen);
-   d = str2cstr(data, &dlen);
+   k = rb_str2cstr(key, &klen);
+   d = rb_str2cstr(data, &dlen);
    if (cdb_make_add(cdb, k, klen, d, dlen) == -1) rb_sys_fail(0);
 
    return obj;
