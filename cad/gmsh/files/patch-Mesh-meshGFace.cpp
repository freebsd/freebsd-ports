--- Mesh/meshGFace.cpp-orig	2014-11-28 19:32:56.000000000 +0000
+++ Mesh/meshGFace.cpp	2014-11-28 19:34:10.000000000 +0000
@@ -156,7 +156,7 @@
 	MEdge E = _gf->quadrangles[i]->getEdge(j);
 	SPoint2 p1, p2;
 	reparamMeshEdgeOnFace(E.getVertex(0),E.getVertex(1),_gf,p1,p2);
-	std::map<MEdge, MVertex *>::iterator it = _middle.find(E);
+	std::map<MEdge, MVertex *, Less_Edge>::iterator it = _middle.find(E);
 	std::map<MEdge, MVertex *, Less_Edge>::iterator it2 = eds.find(E);
 	m[j] = p1;
 	if (it == _middle.end() && it2 == eds.end()){
