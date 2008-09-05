--- ../kcal/incidenceformatter.cpp	2008/09/03 18:28:53	856767
+++ ../kcal/incidenceformatter.cpp	2008/09/03 18:33:54	856768
@@ -1132,6 +1132,9 @@
     IncidenceCompareVisitor() : mExistingIncidence( 0 ) {}
     bool act( IncidenceBase *incidence, Incidence *existingIncidence )
     {
+      if (!existingIncidence) {
+        return false;
+      }
       Incidence *inc = dynamic_cast<Incidence *>( incidence );
       if ( inc && inc->revision() <= existingIncidence->revision() ) {
         return false;
