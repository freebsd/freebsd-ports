--- bibcxx/IOManager/MeshReader.cxx.orig	2026-09-11 16:05:37 UTC
+++ bibcxx/IOManager/MeshReader.cxx
@@ -182,7 +182,8 @@ void MeshReader::readIncompleteMeshFromMedFile( Incomp
     }
     const auto globNum = curMesh->getGlobalNodeNumberingAtSequence( -1, -1 );
     if ( globNum.size() != 0 ) {
-        toReturn->setLocalToGlobalNodeIds( globNum );
+	// Now the FreeBSD ports of MED, PETSc, etc. use 32 bits intergers
+        toReturn->setLocalToGlobalNodeIds( VectorLong( globNum.begin(), globNum.end() ) );
     } else {
         VectorLong nodeGlobNum;
         const auto size = toReturn->getNumberOfNodes();
