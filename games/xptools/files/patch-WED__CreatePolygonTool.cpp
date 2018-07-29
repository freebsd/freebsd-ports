--- src/WEDMap/WED_CreatePolygonTool.cpp.orig	2018-07-05 13:24:15 UTC
+++ src/WEDMap/WED_CreatePolygonTool.cpp
@@ -350,12 +350,18 @@ void	WED_CreatePolygonTool::AcceptPath(
 		pol_info_t info;
 
 		if(rmgr->GetPol(mResource.value, info))
+		{
 			if (!info.mUVBox.is_null())
+			{
 				dpol->SetSubTexture(info.mUVBox);
+			}
 			else
+			{
 				dpol->SetSubTexture(Bbox2(0,0,1,1));
-
+			}
 		dpol->Redrape();
+		}
+		
 	}
 	else if (mType == create_Hole && host->GetClass() == WED_DrapedOrthophoto::sClass)   // holes in orthos also need UV map set
 		dynamic_cast <WED_DrapedOrthophoto *> (host)->Redrape();
