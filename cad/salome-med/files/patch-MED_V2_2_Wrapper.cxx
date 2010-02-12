--- src/MEDWrapper/V2_2/MED_V2_2_Wrapper.cxx.orig	2009-06-04 16:07:01.000000000 +0700
+++ src/MEDWrapper/V2_2/MED_V2_2_Wrapper.cxx	2009-06-04 16:07:21.000000000 +0700
@@ -95,7 +95,11 @@
   void
   GetVersionRelease<eV2_2>(TInt& majeur, TInt& mineur, TInt& release)
   {
-    MEDversionDonner(&majeur, &mineur, &release);
+    med_int a,b,c;
+    a=majeur;
+    b=mineur;
+    c=release;
+    MEDversionDonner(&a, &b, &c);
   }
 
   template<>
