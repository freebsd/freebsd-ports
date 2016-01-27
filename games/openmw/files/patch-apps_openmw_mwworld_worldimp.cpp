--- apps/openmw/mwworld/worldimp.cpp.orig	2016-01-12 16:11:28 UTC
+++ apps/openmw/mwworld/worldimp.cpp
@@ -108,7 +108,7 @@ namespace MWWorld
         }
 
         private:
-          typedef std::tr1::unordered_map<std::string, ContentLoader*> LoadersContainer;
+          typedef std::unordered_map<std::string, ContentLoader*> LoadersContainer;
           LoadersContainer mLoaders;
     };
 
