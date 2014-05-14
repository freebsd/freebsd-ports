--- ./backends/postgresql/statement.cpp.orig	2014-05-05 16:49:26.985995826 +0200
+++ ./backends/postgresql/statement.cpp	2014-05-05 16:46:18.049008548 +0200
@@ -453,7 +453,7 @@
     // pointer to it, so we can't rely on implicit conversion here.
     const char * const resultStr = PQcmdTuples(result_.get_result());
     char * end;
-    long long result = std::strtoll(resultStr, &end, 0);
+    long long result = strtoq(resultStr, &end, 0);
     if (end != resultStr)
     {
         return result;
