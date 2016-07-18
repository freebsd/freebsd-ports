--- _mssql.pyx.orig	2014-10-24 22:03:00 UTC
+++ _mssql.pyx
@@ -1677,12 +1677,10 @@ cdef int _tds_ver_str_to_constant(verstr
         return DBVERSION_42
     if verstr == u'7.0':
         return DBVERSION_70
-    if verstr == u'7.1':
+    if verstr in (u'7.1', u'8.0'):
         return DBVERSION_71
     if verstr == u'7.2':
         return DBVERSION_72
-    if verstr == u'8.0':
-        return DBVERSION_80
     raise MSSQLException('unrecognized tds version: %s' % verstr)
 
 #######################
