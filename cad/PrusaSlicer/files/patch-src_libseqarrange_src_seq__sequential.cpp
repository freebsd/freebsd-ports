--- src/libseqarrange/src/seq_sequential.cpp.orig	2025-07-01 13:42:42 UTC
+++ src/libseqarrange/src/seq_sequential.cpp
@@ -11679,11 +11679,11 @@ bool optimize_SubglobalConsequentialPolygonNonoverlapp
 		{
 		    printf("  %d\n", undecided[j]);
 		}
-		printf("Missing\n");
-		for (unsigned int j = 0; j < missing.size(); ++j)
-		{
-		    printf("  %d\n", missing[j]);
-		}		
+//		printf("Missing\n");
+//		for (unsigned int j = 0; j < missing.size(); ++j)
+//		{
+//		    printf("  %d\n", missing[j]);
+//		}		
 		printf("Decided\n");
 		for (unsigned int j = 0; j < decided_polygons.size(); ++j)
 		{
