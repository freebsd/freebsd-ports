--- libsolidity/codegen/ir/IRGeneratorForStatements.cpp.orig	2020-02-20 13:32:21 UTC
+++ libsolidity/codegen/ir/IRGeneratorForStatements.cpp
@@ -968,7 +968,7 @@ void IRGeneratorForStatements::endVisit(IndexAccess co
 			*_indexAccess.annotation().type,
 			IRLValue::Storage{
 				slot,
-				0
+				0u
 			}
 		});
 	}
