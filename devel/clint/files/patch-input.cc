--- src/input.cc.orig	Fri Sep  6 22:17:58 2002
+++ src/input.cc	Fri Sep  6 22:21:11 2002
@@ -70,17 +70,17 @@
    std::string Input::parse_cpp(std::string line) {
       if (line[0] == '#') {
 #ifdef HAVE_SSTREAM
-         istringstream in(line);
+         std::istringstream in(line);
 #else
          istrstream in(line.c_str());
 #endif // HAVE_SSTREAM
          in.get(); // remove '#'
-         string command;
+         std::string command;
          while (isalnum(in.peek()) && not in.eof()){
             command+=in.get();
          }
-         cerr << "line = \"" << line << "\" command = \"" << command << "\" ";
-         if (command == string("include") ) {
+         std::cerr << "line = \"" << line << "\" command = \"" << command << "\" ";
+         if (command == std::string("include") ) {
          } else if ( command == "define" ) {
          } else if ( command == "undef" ) {
          } else if ( command == "if" ) {
@@ -101,7 +101,7 @@
             // Apparently this is valid
             // Ignore this
          } else {
-            cerr << "Unknown preprocessor macro" << endl;
+            std::cerr << "Unknown preprocessor macro" << std::endl;
          }
       }
       return line;
