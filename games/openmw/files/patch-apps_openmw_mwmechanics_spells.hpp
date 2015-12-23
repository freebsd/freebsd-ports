--- apps/openmw/mwmechanics/spells.hpp.orig	2015-11-24 02:42:35 UTC
+++ apps/openmw/mwmechanics/spells.hpp
@@ -31,7 +31,7 @@ namespace MWMechanics
     {
         public:
 
-            typedef std::map<std::string, std::map<const int, float> > TContainer; // ID, <effect index, normalised random magnitude>
+            typedef std::map<std::string, std::map<int, float> > TContainer; // ID, <effect index, normalised random magnitude>
             typedef TContainer::const_iterator TIterator;
 
             struct CorprusStats
