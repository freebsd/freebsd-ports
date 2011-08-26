--- libs/Music/Music.h.orig	2011-01-28 08:09:11.000000000 +0900
+++ libs/Music/Music.h	2011-08-21 21:51:54.000000000 +0900
@@ -285,7 +285,7 @@
     // TODO cannot create a template so easily because the pow10 is not defined for all types
     inline double invlp(double value)
     {
-        return pow10(value/20.0);
+        return pow(10.0,value/20.0);
 //         return pow(TYPE(10), value/TYPE(20));
     }
 
