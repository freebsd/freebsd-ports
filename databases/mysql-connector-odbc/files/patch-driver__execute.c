--- driver/execute.c.orig	2011-10-04 23:19:00.000000000 +0300
+++ driver/execute.c	2011-10-15 12:07:45.000000000 +0300
@@ -424,11 +424,19 @@
             data= buff;
             break;
         case SQL_C_SBIGINT:
+#ifdef MARIADB_BASE_VERSION
+            length= longlong2str(*((longlong*) data),buff, -10, 1) - buff;
+#else
             length= longlong2str(*((longlong*) data),buff, -10) - buff;
+#endif
             data= buff;
             break;
         case SQL_C_UBIGINT:
+#ifdef MARIADB_BASE_VERSION
+            length= longlong2str(*((ulonglong*) data),buff, 10, 1) - buff;
+#else
             length= longlong2str(*((ulonglong*) data),buff, 10) - buff;
+#endif
             data= buff;
             break;
         case SQL_C_FLOAT:
