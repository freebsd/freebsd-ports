--- _mssql.pxd.orig	2014-08-29 22:32:10 UTC
+++ _mssql.pxd
@@ -35,7 +35,7 @@ cdef class MSSQLConnection:
     cpdef cancel(self)
     cdef void clear_metadata(self)
     cdef object convert_db_value(self, BYTE *, int, int)
-    cdef int convert_python_value(self, object value, BYTE **, int*, int*) except -1
+    cdef int convert_python_value(self, object value, BYTE **dbValue, int *dbtype, int *length) except 1
     cpdef execute_query(self, query, params=?)
     cpdef execute_non_query(self, query, params=?)
     cpdef execute_row(self, query, params=?)
