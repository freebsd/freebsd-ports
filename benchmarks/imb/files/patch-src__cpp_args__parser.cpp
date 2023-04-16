--- src_cpp/args_parser.cpp.orig	2021-10-01 13:09:19 UTC
+++ src_cpp/args_parser.cpp
@@ -299,7 +299,7 @@ void args_parser::print_help_advice() const {
 #endif
 
 void args_parser::print_help_advice() const {
-    sout << "Try \"" <<  basename(argv[0]) << " " << option_starter << "help\" for usage information" << endl;
+    sout << "Try \"" <<  basename(const_cast<char*>(argv[0])) << " " << option_starter << "help\" for usage information" << endl;
 }
 
 // NOTE: This one is just to loop over expected_args 2-level array in a easier way.
@@ -381,10 +381,10 @@ void args_parser::print_help() const {
 void args_parser::print_help() const {
     if (program_name.size() != 0)
         sout << program_name << endl;
-    sout << "Usage: " << basename(argv[0]) << " ";
+    sout << "Usage: " << basename(const_cast<char*>(argv[0])) << " ";
     string header;
     header +=  "Usage: ";
-    header += basename(argv[0]); 
+    header += basename(const_cast<char*>(argv[0])); 
     header += " ";
     size_t size = min(header.size(), (size_t)16);
     string tab(size - 2, ' ');
