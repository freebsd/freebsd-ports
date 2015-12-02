--- components/esm/spellstate.hpp.orig	2015-11-24 02:42:35 UTC
+++ components/esm/spellstate.hpp
@@ -28,7 +28,7 @@ namespace ESM
             float mMagnitude;
         };
 
-        typedef std::map<std::string, std::map<const int, float> > TContainer;
+        typedef std::map<std::string, std::map<int, float> > TContainer;
         TContainer mSpells;
 
         std::map<std::string, std::vector<PermanentSpellEffectInfo> > mPermanentSpellEffects;
