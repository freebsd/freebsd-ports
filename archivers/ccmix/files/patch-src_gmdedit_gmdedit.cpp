--- src/gmdedit/gmdedit.cpp.orig	2017-06-12 14:07:35 UTC
+++ src/gmdedit/gmdedit.cpp
@@ -83,10 +83,6 @@ int main(int argc, char** argv) {
     std::fstream ofh;
     std::vector<t_namepair> names;
     
-    ifh.open(argv[1], std::ios_base::in|std::ios_base::binary);
-    gmd.readDB(ifh);
-    ifh.close();
-    
     if(argc < 4){
         //menu();
         std::cout << "Use: gmdedit gmdpath additionspath newgmdpath\n";
@@ -106,6 +102,10 @@ int main(int argc, char** argv) {
             }
         }
     }
+
+    ifh.open(argv[1], std::ios_base::in|std::ios_base::binary);
+    gmd.readDB(ifh);
+    ifh.close();
 
     for(unsigned int i = 0; i < names.size(); i++) {
         gmd.addName(game, names[i].first, names[i].second);
