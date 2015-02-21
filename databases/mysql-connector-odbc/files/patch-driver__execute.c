--- driver/execute.c.orig	2014-11-05 14:41:16.000000000 +0300
+++ driver/execute.c	2014-11-05 14:44:10.000000000 +0300
@@ -563,11 +563,19 @@
         *res= buff;
         break;
     case SQL_C_SBIGINT:
+#ifdef MARIADB_BASE_VERSION
+        *length= longlong2str(*((longlong*) *res), buff, -10, 1) - buff;
+#else
         *length= longlong2str(*((longlong*) *res), buff, -10) - buff;
+#endif
         *res= buff;
         break;
     case SQL_C_UBIGINT:
+#ifdef MARIADB_BASE_VERSION
+        *length= longlong2str(*((ulonglong*) *res), buff, 10, 1) - buff;
+#else
         *length= longlong2str(*((ulonglong*) *res), buff, 10) - buff;
+#endif
         *res= buff;
         break;
     case SQL_C_FLOAT:
