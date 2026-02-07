--- src/cf/main.cpp.orig	2018-11-05 15:29:43 UTC
+++ src/cf/main.cpp
@@ -173,7 +173,7 @@ static void parse_options( int argc, cha
       else opts.sfx = opts.music = false;
     } else {
       if (strcmp(argv[argc], "--version") == 0)
-        cout << PROGRAMNAME" "VERSION << endl;
+        cout << PROGRAMNAME " " VERSION << endl;
       else print_usage( argv[0] );
       exit ( 0 );
     }
