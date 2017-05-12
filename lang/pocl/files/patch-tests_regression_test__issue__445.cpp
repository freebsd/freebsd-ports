--- tests/regression/test_issue_445.cpp.orig	2017-04-05 14:15:40 UTC
+++ tests/regression/test_issue_445.cpp
@@ -29,7 +29,7 @@ private_local_array(__global int *__rest
 }
 )CLC";
 
-int main(int, char *)
+int main(int, char **)
 {
   try {
     int N = 9;
