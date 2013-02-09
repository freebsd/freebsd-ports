--- backends/postgresql/statement.cpp.orig	2012-06-19 19:22:42.029810018 +0300
+++ backends/postgresql/statement.cpp	2012-06-19 19:23:24.256806727 +0300
@@ -445,7 +445,11 @@ long long postgresql_statement_backend::
 {
     const char * resultStr = PQcmdTuples(result_);
     char * end;
+#ifdef __FreeBSD__
+    long long result = strtoq(resultStr, &end, 0);
+#else
     long long result = strtoll(resultStr, &end, 0);
+#endif
     if (end != resultStr)
     {
         return result;
