--- kpilot/conduits/vcalconduit/vcalRecord.cc.orig	Sun Mar  4 13:37:15 2007
+++ kpilot/conduits/vcalconduit/vcalRecord.cc	Sun Mar  4 13:38:35 2007
@@ -584,7 +584,7 @@
 	if (eventCategories.size() < 1)
 	{
 		// This event has no categories.
-		de->setCategory(Pilot::Unfiled);
+		((PilotRecordBase *)de)->setCategory(Pilot::Unfiled);
 		return;
 	}
 
@@ -623,6 +623,6 @@
 		}
 	}
 
-	de->setCategory(Pilot::Unfiled);
+	((PilotRecordBase *)de)->setCategory(Pilot::Unfiled);
 }
 
