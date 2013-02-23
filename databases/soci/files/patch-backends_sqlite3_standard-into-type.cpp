--- backends/sqlite3/standard-into-type.cpp.orig	2012-06-19 19:12:10.168809305 +0300
+++ backends/sqlite3/standard-into-type.cpp	2012-06-19 19:22:12.580359214 +0300
@@ -113,7 +113,11 @@ void sqlite3_standard_into_type_backend:
         case x_long_long:
             {
                 long long* dest = static_cast<long long*>(data_);
+#ifdef __FreeBSD__
+                *dest = strtoq(buf, NULL, 10);
+#else
                 *dest = strtoll(buf, NULL, 10);
+#endif
             }
             break;
         case x_unsigned_long_long:
@@ -142,7 +146,11 @@ void sqlite3_standard_into_type_backend:
 
                 rowid *rid = static_cast<rowid *>(data_);
                 sqlite3_rowid_backend *rbe = static_cast<sqlite3_rowid_backend *>(rid->get_backend());
+#ifdef __FreeBSD__
+                long long val = strtoq(buf, NULL, 10);
+#else
                 long long val = strtoll(buf, NULL, 10);
+#endif
                 rbe->value_ = static_cast<unsigned long>(val);
             }
             break;
