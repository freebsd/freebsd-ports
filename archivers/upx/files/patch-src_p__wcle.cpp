--- src/p_wcle.cpp.orig	2018-08-26 02:58:09 UTC
+++ src/p_wcle.cpp
@@ -763,6 +763,7 @@ void PackWcle::decodeEntryTable()
     }
 
     //if (Opt_debug) printf("\n%d entries decoded.\n",n);
+    UNUSED(n);
 
     soentries = ptr_diff(p, ientries) + 1;
     oentries = ientries;
