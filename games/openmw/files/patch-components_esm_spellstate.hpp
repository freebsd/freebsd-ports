--- components/esm/spellstate.hpp.orig	2016-01-12 16:11:28 UTC
+++ components/esm/spellstate.hpp
@@ -28,7 +28,7 @@ namespace ESM
             float mMagnitude;
         };
 
-        typedef std::map<std::string, std::map<const int, float> > TContainer;
+        typedef std::map<std::string, std::map<int, float> > TContainer;
         TContainer mSpells;
 
         std::map<std::string, std::vector<PermanentSpellEffectInfo> > mPermanentSpellEffects;
