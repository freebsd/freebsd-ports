--- apps/openmw/mwmechanics/spells.hpp.orig	2016-01-19 22:25:34 UTC
+++ apps/openmw/mwmechanics/spells.hpp
@@ -33,7 +33,7 @@ namespace MWMechanics
 
             typedef const ESM::Spell* SpellKey;
 
-            typedef std::map<SpellKey, std::map<const int, float> > TContainer; // ID, <effect index, normalised random magnitude>
+            typedef std::map<SpellKey, std::map<int, float> > TContainer; // ID, <effect index, normalised random magnitude>
             typedef TContainer::const_iterator TIterator;
 
             struct CorprusStats
