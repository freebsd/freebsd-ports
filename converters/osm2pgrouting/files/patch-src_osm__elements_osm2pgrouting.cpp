--- src/osm_elements/osm2pgrouting.cpp.orig	2020-08-20 05:44:56 UTC
+++ src/osm_elements/osm2pgrouting.cpp
@@ -140,7 +140,7 @@ int main(int argc, char* argv[]) {
                 cout << "Can't open database" << endl;
                 return 1;
             }
-            C.disconnect ();
+            C.close ();
         }catch (const std::exception &e){
             cerr << e.what() << std::endl;
             return 1;
