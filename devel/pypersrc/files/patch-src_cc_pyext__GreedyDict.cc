--- src/cc/pyext_GreedyDict.cc.orig	2018-08-27 20:07:54 UTC
+++ src/cc/pyext_GreedyDict.cc
@@ -57,7 +57,7 @@ GreedyDict_New( PyObject* nil, PyObject* args )
 	{
 		// Create a GreedyDict C++ object and associate with a Python self object.
 		GreedyDict* greedyDict = new GreedyDict( hintKeySize );
-		sGreedyDictMap.insert( make_pair<PyObject*,GreedyDict*>(self,greedyDict) );
+		sGreedyDictMap.insert( make_pair(self,greedyDict) );
 	}
 	PY_RETURN_NONE
 }
