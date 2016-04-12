--- src/Options.C.orig	1999-05-12 01:40:13 UTC
+++ src/Options.C
@@ -35,7 +35,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <iostream.h>
+#include <iostream>
 
 #include "Options.H"
 
@@ -150,7 +150,7 @@ bool Options::parse(int argc, char **arg
 	case 'p':
 	  _port = atoi(optarg);
 	  if (_port == 0) { // cannot be 0
-	    cerr << *argv << ": port: invalid argument: " <<  optarg << endl;
+	    std::cerr << *argv << ": port: invalid argument: " <<  optarg << std::endl;
 	    bad_params = true;
 	  }
 	  break;
@@ -160,7 +160,7 @@ bool Options::parse(int argc, char **arg
 	  if (2 != (ooo = sscanf(optarg, "%dx%d", &_width, &_height)) ||
 	      _height == 0 ||
 	      _width  == 0) {
-	    cerr << *argv << ": size: invalid argument: " <<  optarg << endl;
+	    std::cerr << *argv << ": size: invalid argument: " <<  optarg << std::endl;
 	    bad_params = true;
 	  }
 	  break;
@@ -168,8 +168,8 @@ bool Options::parse(int argc, char **arg
 	case 'g': // height (server only)
 	  _height = atoi(optarg);
 	  if (_height == 0) { // cannot be 0
-	    cerr << *argv << ": height: invalid argument: " <<  optarg \
-		 << endl;
+	    std::cerr << *argv << ": height: invalid argument: " <<  optarg \
+		 << std::endl;
 	    bad_params = true;
 	  }
 	  break;
@@ -177,8 +177,8 @@ bool Options::parse(int argc, char **arg
 	case 'w': // width (server only)
 	  _width = atoi(optarg);
 	  if (_width == 0) { // cannot be 0
-	    cerr << *argv << ": width: invalid argument: " <<  optarg \
-		 << endl;
+	    std::cerr << *argv << ": width: invalid argument: " <<  optarg \
+		 << std::endl;
 	    bad_params = true;
 	  }
 	  break;
@@ -194,7 +194,7 @@ bool Options::parse(int argc, char **arg
 
   if (_set == OPTIONS_CLIENT_SET) {
     if (argv[optind] == NULL) {
-      cerr << *argv << ": missing player name" << endl;
+      std::cerr << *argv << ": missing player name" << std::endl;
       bad_params = true;
     }
     else {
@@ -208,7 +208,7 @@ bool Options::parse(int argc, char **arg
       if (p != 0)
 	_port = p;
       else {
-	cerr << *argv << ": too many parameters: " << argv[optind] << endl;
+	std::cerr << *argv << ": too many parameters: " << argv[optind] << std::endl;
 	bad_params = true;
       }
     }
@@ -227,34 +227,34 @@ int main(int argc, char **argv)
   options.set_option_set(0);
   
   if (!options.parse(argc, argv)) {
-    cout << "usage: .... " << endl;
+    std::cout << "usage: .... " << std::endl;
     delete &options;
     return 1;
   }
 
   if (options.is_help()) {
-    cout << "help: ..." << endl;
+    std::cout << "help: ..." << std::endl;
     delete &options;
     return 0;
   }
 
   if (options.is_version()) {
-    cout << "... version ... " << endl;
+    std::cout << "... version ... " << std::endl;
     delete &options;
     return 0;
   }
     
-  cout << "host:  " << options.get_host_name() << ":" \
-       << options.get_port() << endl;
-  cout << "message_file: " << options.get_message_file() << endl;
-  cout << "twokey(" << options.is_twokey() << ")  debug(" \
-       << options.is_debug() <<")" << endl;
+  std::cout << "host:  " << options.get_host_name() << ":" \
+       << options.get_port() << std::endl;
+  std::cout << "message_file: " << options.get_message_file() << std::endl;
+  std::cout << "twokey(" << options.is_twokey() << ")  debug(" \
+       << options.is_debug() <<")" << std::endl;
   
   int i = options.get_nonoption_index();
-  cout << "argv left = " << endl;
+  std::cout << "argv left = " << std::endl;
   argv += i;
   while (*argv) {
-    cout << "   " << *argv++ << endl;
+    std::cout << "   " << *argv++ << std::endl;
   }
 
   delete &options;
