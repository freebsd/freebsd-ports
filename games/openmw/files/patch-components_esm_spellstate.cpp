--- components/esm/spellstate.cpp.orig	2016-01-12 16:11:28 UTC
+++ components/esm/spellstate.cpp
@@ -12,7 +12,7 @@ namespace ESM
         {
             std::string id = esm.getHString();
 
-            std::map<const int, float> random;
+            std::map<int, float> random;
             while (esm.isNextSub("INDX"))
             {
                 int index;
@@ -73,8 +73,8 @@ namespace ESM
         {
             esm.writeHNString("SPEL", it->first);
 
-            const std::map<const int, float>& random = it->second;
-            for (std::map<const int, float>::const_iterator rIt = random.begin(); rIt != random.end(); ++rIt)
+            const std::map<int, float>& random = it->second;
+            for (std::map<int, float>::const_iterator rIt = random.begin(); rIt != random.end(); ++rIt)
             {
                 esm.writeHNT("INDX", rIt->first);
                 esm.writeHNT("RAND", rIt->second);
