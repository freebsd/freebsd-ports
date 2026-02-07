--- framework/frontend/OutputDihedrals.cpp.orig	2008-03-25 22:53:27.000000000 +0100
+++ framework/frontend/OutputDihedrals.cpp	2008-03-25 22:52:21.000000000 +0100
@@ -387,10 +387,10 @@
     string atom3name = "";
     string atom4name = "";
 
-    std::set< int >::iterator myAtomSet_itr1 = NULL;
-    std::set< int >::iterator myAtomSet_itr2 = NULL;
-    std::set< int >::iterator myAtomSet_itr3 = NULL;
-    std::set< int >::iterator myAtomSet_itr4 = NULL;
+    std::set< int >::iterator myAtomSet_itr1;
+    std::set< int >::iterator myAtomSet_itr2;
+    std::set< int >::iterator myAtomSet_itr3;
+    std::set< int >::iterator myAtomSet_itr4;
 
     for(unsigned int i=0; i < myTopology->dihedrals.size();i++){
       
