--- apps/essimporter/converter.hpp.orig	2015-11-22 18:54:17 UTC
+++ apps/essimporter/converter.hpp
@@ -118,7 +118,7 @@ public:
         {
             mContext->mPlayer.mObject.mCreatureStats.mLevel = npc.mNpdt52.mLevel;
             mContext->mPlayerBase = npc;
-            std::map<const int, float> empty;
+            std::map<int, float> empty;
             // FIXME: player start spells and birthsign spells aren't listed here,
             // need to fix openmw to account for this
             for (std::vector<std::string>::const_iterator it = npc.mSpells.mList.begin(); it != npc.mSpells.mList.end(); ++it)
