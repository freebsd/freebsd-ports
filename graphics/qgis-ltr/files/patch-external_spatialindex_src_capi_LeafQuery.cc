--- external/spatialindex/src/capi/LeafQuery.cc.orig	2026-07-31 12:35:21 UTC
+++ external/spatialindex/src/capi/LeafQuery.cc
@@ -33,6 +33,11 @@ LeafQuery::LeafQuery() 
 
 }
 
+LeafQuery::~LeafQuery()
+{
+
+}
+
 LeafQueryResult get_results(const SpatialIndex::INode* n)
 {
 	LeafQueryResult result (n->getIdentifier());
