--- src/MathHeaders.h.orig	Sun Dec  8 04:58:58 2002
+++ src/MathHeaders.h	Sun Sep 12 00:15:42 2004
@@ -63,12 +63,12 @@
         public:
         
         union {
-        struct { mpl_real R,I,J,K; }; 
+        struct { mpl_real R,I,J,K; } m; 
         mpl_real real;
         mpl_vector vector;
         mpl_complex complex;
         mpl_rational rational;
-        };
+        } mpl;
         
         int  type;
         char pwrs[COUNT];  // Used in unit calculation
