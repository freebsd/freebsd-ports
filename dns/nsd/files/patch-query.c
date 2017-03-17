--- query.c.orig	2017-03-09 14:53:32 UTC
+++ query.c
@@ -664,7 +664,7 @@ add_additional_rrsets(struct query *quer
 			temp->rnode = NULL;
 			temp->dname = additional->dname;
 #else
-			memcpy(&temp->node, &additional->node, sizeof(rbnode_t));
+			memcpy(&temp->node, &additional->node, sizeof(rbnode_type));
 			temp->node.parent = NULL;
 #endif
 			temp->number = additional->number;
@@ -1113,7 +1113,7 @@ answer_authoritative(struct nsd   *nsd,
 		match->rnode = NULL;
 		match->dname = wildcard_child->dname;
 #else
-		memcpy(&match->node, &wildcard_child->node, sizeof(rbnode_t));
+		memcpy(&match->node, &wildcard_child->node, sizeof(rbnode_type));
 		match->node.parent = NULL;
 #endif
 		match->parent = closest_encloser;
