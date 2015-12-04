--- apps/openmw/mwmechanics/spells.cpp.orig	2015-11-24 02:42:35 UTC
+++ apps/openmw/mwmechanics/spells.cpp
@@ -29,7 +29,7 @@ namespace MWMechanics
     {
         if (mSpells.find (spell->mId)==mSpells.end())
         {
-            std::map<const int, float> random;
+            std::map<int, float> random;
 
             // Determine the random magnitudes (unless this is a castable spell, in which case
             // they will be determined when the spell is cast)
