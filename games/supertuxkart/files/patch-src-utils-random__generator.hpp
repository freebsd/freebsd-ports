--- src/utils/random_generator.hpp.orig	2011-12-06 22:43:36.000000000 +0400
+++ src/utils/random_generator.hpp	2013-09-13 21:51:20.971227530 +0400
@@ -21,6 +21,7 @@
 
 #include <algorithm>
 #include <vector>
+#include <cstdlib> // for rand()
 
 /** A random number generator. Each objects that needs a random number uses
     its own number random generator. They are all seeded with number provided
