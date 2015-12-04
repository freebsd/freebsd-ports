--- apps/openmw/mwworld/worldimp.cpp.orig	2015-11-22 18:54:17 UTC
+++ apps/openmw/mwworld/worldimp.cpp
@@ -108,7 +108,7 @@ namespace MWWorld
         }
 
         private:
-          typedef std::tr1::unordered_map<std::string, ContentLoader*> LoadersContainer;
+          typedef std::unordered_map<std::string, ContentLoader*> LoadersContainer;
           LoadersContainer mLoaders;
     };
 
