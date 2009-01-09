--- driver/myodbc3.h.orig	2008-07-02 06:43:38.000000000 -0800
+++ driver/myodbc3.h	2009-01-08 11:59:38.000000000 -0900
@@ -161,7 +161,7 @@
 #define FLAG_MIN_DATE_TO_ZERO (1 << 25) /* Convert ODBC min date to 0000-00-00 on query */
 #define FLAG_MULTI_STATEMENTS (1 << 26) /* Allow multiple statements in a query */
 #define FLAG_COLUMN_SIZE_S32 (1 << 27) /* Limit column size to a signed 32-bit value (automatically set for ADO) */
-#define FLAG_NO_BINARY_RESULT (1 << 28) /* Disables charset 63 for columns with empty org_table */
+#define FLAG_NO_BINARY_RESULT (1 << 28) /* Disables charset 63 for columns with empty org_table */
 
 /* We don't make any assumption about what the default may be. */
 #ifndef DEFAULT_TXN_ISOLATION
@@ -252,8 +252,8 @@
   SQLINTEGER    ValueMax;
   SQLLEN *      actual_len;
   SQLINTEGER    value_length;
-  bool	        alloced,used;
-  bool	        real_param_done;
+  my_bool	        alloced,used;
+  my_bool	        real_param_done;
 } PARAM_BIND;
 
 
