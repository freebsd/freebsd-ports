--- apps/openmw/mwmechanics/spells.cpp.orig	2016-01-19 22:26:03 UTC
+++ apps/openmw/mwmechanics/spells.cpp
@@ -44,7 +44,7 @@ namespace MWMechanics
     {
         if (mSpells.find (spell)==mSpells.end())
         {
-            std::map<const int, float> random;
+            std::map<int, float> random;
 
             // Determine the random magnitudes (unless this is a castable spell, in which case
             // they will be determined when the spell is cast)
