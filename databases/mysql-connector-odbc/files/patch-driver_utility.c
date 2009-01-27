--- driver/utility.c.orig	2009-01-27 00:14:43.000000000 +0600
+++ driver/utility.c	2009-01-27 00:15:46.000000000 +0600
@@ -504,11 +504,6 @@
 
     return field_is_binary ? SQL_BINARY : SQL_CHAR;
 
-  /*
-    MYSQL_TYPE_VARCHAR is never actually sent, this just silences
-    a compiler warning.
-  */
-  case MYSQL_TYPE_VARCHAR:
   case MYSQL_TYPE_VAR_STRING:
     if (buff)
       (void)strmov(buff, field_is_binary ? "varbinary" : "varchar");
@@ -657,7 +652,6 @@
 
   case MYSQL_TYPE_ENUM:
   case MYSQL_TYPE_SET:
-  case MYSQL_TYPE_VARCHAR:
   case MYSQL_TYPE_VAR_STRING:
   case MYSQL_TYPE_STRING:
   case MYSQL_TYPE_TINY_BLOB:
@@ -783,7 +777,6 @@
 
   case MYSQL_TYPE_ENUM:
   case MYSQL_TYPE_SET:
-  case MYSQL_TYPE_VARCHAR:
   case MYSQL_TYPE_VAR_STRING:
   case MYSQL_TYPE_STRING:
   case MYSQL_TYPE_TINY_BLOB:
@@ -867,7 +860,6 @@
 
   case MYSQL_TYPE_ENUM:
   case MYSQL_TYPE_SET:
-  case MYSQL_TYPE_VARCHAR:
   case MYSQL_TYPE_VAR_STRING:
   case MYSQL_TYPE_STRING:
   case MYSQL_TYPE_TINY_BLOB:
