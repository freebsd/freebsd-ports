--- src/solvers/sat/external_sat.cpp.orig	2023-10-30 12:11:18 UTC
+++ src/solvers/sat/external_sat.cpp
@@ -119,8 +119,8 @@ external_satt::resultt external_satt::parse_result(std
       {
         try
         {
-          signed long long as_long = std::stol(assignment_string);
-          size_t index = std::labs(as_long);
+          signed long long as_long = std::stoll(assignment_string);
+          size_t index = std::llabs(as_long);
 
           if(index >= number_of_variables)
           {
