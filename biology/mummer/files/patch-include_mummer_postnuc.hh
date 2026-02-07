--- include/mummer/postnuc.hh.orig	2020-10-25 22:49:14 UTC
+++ include/mummer/postnuc.hh
@@ -67,7 +67,7 @@ struct Alignment
                                 //      trust me, it is a very helpful value
   long int         Errors, SimErrors, NonAlphas; // errors, similarity errors, nonalphas
 
-  Alignment(const Match& m, const char dir)
+  Alignment(const Match& m, const signed char dir)
     : dirB(dir)
     , sA(m.sA)
     , sB(m.sB)
