--- include/dsrpdb/geometry_internal.h.orig	2019-01-29 07:04:14 UTC
+++ include/dsrpdb/geometry_internal.h
@@ -59,7 +59,7 @@ namespace dsrpdb {
 	unsigned int b= it->second;
 	assert(a < map.size() && b < map.size());
 	if (map[a] !=-1 && map[b]!=-1) { 
-	  *bout = std::pair<int,int>(map[a], map[b]);
+	  *bout = std::pair<dsrpdb::PDB_index<dsrpdb::Atom>,dsrpdb::PDB_index<dsrpdb::Atom>>(map[a], map[b]);
 	  ++bout;
 	}
       }
