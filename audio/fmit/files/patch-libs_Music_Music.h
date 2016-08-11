--- libs/Music/Music.h.orig	2014-05-30 11:38:46 UTC
+++ libs/Music/Music.h
@@ -285,7 +285,7 @@ namespace Music
     // TODO cannot create a template so easily because the pow10 is not defined for all types
     inline double invlp(double value)
     {
-        return pow10(value/20.0);
+        return pow(10.0,value/20.0);
 //         return pow(TYPE(10), value/TYPE(20));
     }
 
