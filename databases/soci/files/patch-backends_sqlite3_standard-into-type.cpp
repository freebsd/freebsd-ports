--- ./backends/sqlite3/standard-into-type.cpp.orig	2013-08-22 00:40:11.000000000 +0200
+++ ./backends/sqlite3/standard-into-type.cpp	2014-05-05 16:45:06.981013401 +0200
@@ -107,7 +107,7 @@
         case x_long_long:
             {
                 long long* dest = static_cast<long long*>(data_);
-                *dest = std::strtoll(buf, NULL, 10);
+                *dest = strtoq(buf, NULL, 10);
             }
             break;
         case x_unsigned_long_long:
@@ -136,7 +136,7 @@
 
                 rowid *rid = static_cast<rowid *>(data_);
                 sqlite3_rowid_backend *rbe = static_cast<sqlite3_rowid_backend *>(rid->get_backend());
-                long long val = std::strtoll(buf, NULL, 10);
+                long long val = strtoq(buf, NULL, 10);
                 rbe->value_ = static_cast<unsigned long>(val);
             }
             break;
