--- frontends/CsoundAC/Counterpoint.hpp.orig	2015-09-29 11:13:28 UTC
+++ frontends/CsoundAC/Counterpoint.hpp
@@ -102,8 +102,8 @@ public:
   Counterpoint();
   virtual ~Counterpoint();
   int ABS(int i);
-  int MIN(int a, int b);
-  int MAX(int a, int b);
+  int IMIN(int a, int b);
+  int IMAX(int a, int b);
   void ARRBLT(int *dest, int *source, int num);
   enum
     {
