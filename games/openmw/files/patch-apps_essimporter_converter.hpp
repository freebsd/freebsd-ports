--- apps/essimporter/converter.hpp.orig	2016-01-12 16:11:28 UTC
+++ apps/essimporter/converter.hpp
@@ -121,7 +121,7 @@ public:
         {
             mContext->mPlayer.mObject.mCreatureStats.mLevel = npc.mNpdt52.mLevel;
             mContext->mPlayerBase = npc;
-            std::map<const int, float> empty;
+            std::map<int, float> empty;
             // FIXME: player start spells and birthsign spells aren't listed here,
             // need to fix openmw to account for this
             for (std::vector<std::string>::const_iterator it = npc.mSpells.mList.begin(); it != npc.mSpells.mList.end(); ++it)
