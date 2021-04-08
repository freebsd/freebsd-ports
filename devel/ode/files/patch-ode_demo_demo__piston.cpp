--- ode/demo/demo_piston.cpp.orig	2013-08-19 17:48:05 UTC
+++ ode/demo/demo_piston.cpp
@@ -659,7 +659,7 @@ int main (int argc, char **argv)
                 {
                     int j = i+1;
                     if ( j+1 > argc      ||  // Check if we have enough arguments
-                            argv[j] == '\0' ||  // We should have a path here
+                            argv[j][0] == '\0' ||  // We should have a path here
                             argv[j][0] == '-' ) // We should have a path not a command line
                         Help (argv);
                     else
