--- src/WEDMap/WED_CreateEdgeTool.cpp.orig	2018-07-05 09:49:45 UTC
+++ src/WEDMap/WED_CreateEdgeTool.cpp
@@ -413,6 +413,8 @@ void WED_CreateEdgeTool::FindNear(WED_Th
 				for(int n = 0; n < c->GetNumEntities(); ++n)
 					FindNear(NULL,c->GetNthEntity(n), filter, loc, out_thing, out_dsq);
 			}
+		default:
+			break;
 		}
 	}
 	else
@@ -485,6 +487,8 @@ void WED_CreateEdgeTool::FindNearP2S(WED
 				for(int n = 0; n < c->GetNumEntities(); ++n)
 					FindNearP2S(NULL,c->GetNthEntity(n), filter, loc, out_thing, out_dsq);
 			}
+		default:
+			break;
 		}
 	}
 	else
