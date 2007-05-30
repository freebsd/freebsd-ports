--- ngsolve/basiclinalg/calcinverse.cpp.orig	Tue Nov 16 09:38:35 2004
+++ ngsolve/basiclinalg/calcinverse.cpp	Tue May 29 19:27:48 2007
@@ -10,7 +10,7 @@
   {
     double sum = 0;
     for (int i = 0; i < N; i++)
-      sum += abs(m(i,i));
+      sum += std::abs(m(i,i));
     return sum;
   }
   
