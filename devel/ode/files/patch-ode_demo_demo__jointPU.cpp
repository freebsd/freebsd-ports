--- ode/demo/demo_jointPU.cpp.orig	2013-12-06 21:52:14 UTC
+++ ode/demo/demo_jointPU.cpp
@@ -579,7 +579,7 @@ int main (int argc, char **argv)
       if (0 == strcmp ("-t", argv[i]) || 0 == strcmp ("--texture-path", argv[i]) ) {
         int j = i+1;
         if ( j+1 > argc      ||  // Check if we have enough arguments
-             argv[j] == '\0' ||  // We should have a path here
+             argv[j][0] == '\0' ||  // We should have a path here
              argv[j][0] == '-' ) // We should have a path not a command line
           Help (argv);
         else
