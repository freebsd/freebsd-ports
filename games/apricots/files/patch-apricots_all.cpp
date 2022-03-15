--- apricots/all.cpp.orig	2021-02-12 23:45:58 UTC
+++ apricots/all.cpp
@@ -18,7 +18,7 @@ int wrap(int n, int min, int max) { return ((((n - min
 
 // Sign function
 
-inline int sign(int n) { return (0 < n) - (n < 0); }
+int sign(int n) { return (0 < n) - (n < 0); }
 
 // Error message for switch statements that shouldn't ever get to default
 
