--- tools/cfed.cpp.orig	2018-11-05 15:29:25 UTC
+++ tools/cfed.cpp
@@ -970,7 +970,7 @@ int main( int argc, char **argv ) {
     for ( i = argc - 1; i > 1; --i ) {
       if (strcmp(argv[i], "--help") == 0) show_help = 1;
       else if (strcmp(argv[i], "--version") == 0) {
-        cout << "cfed "VERSION << endl;
+        cout << "cfed " VERSION << endl;
         return 0;
       }
       else if (strcmp(argv[i-1], "--units") == 0) uset = argv[i];
