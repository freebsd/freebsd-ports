
$FreeBSD$

--- GrfForeach.h.orig
+++ GrfForeach.h
@@ -83,7 +83,7 @@
 		virtual SEQUENCE_INTERRUPTION_LIST executeReverseSortedForeach(DtaScriptVariable& theVariable, DtaScriptVariable& stackForeach);
 		virtual SEQUENCE_INTERRUPTION_LIST executeReverseSortedIndirectForeach(DtaScriptVariable& theVariable, DtaScriptVariable& stackForeach);
 
-		SEQUENCE_INTERRUPTION_LIST GrfForeach::iterate(DtaArrayIterator& iteratorData, DtaScriptVariable& stackForeach);
+		SEQUENCE_INTERRUPTION_LIST iterate(DtaArrayIterator& iteratorData, DtaScriptVariable& stackForeach);
 	};
 }
 
