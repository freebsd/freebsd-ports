--- ../svx/source/svrtf/rtfitem.cxx.orig	Thu Apr 17 22:50:50 2003
+++ ../svx/source/svrtf/rtfitem.cxx	Thu Apr 17 23:40:15 2003
@@ -285,11 +285,20 @@
 	}
 	else
 	{
-		if( LOW_CHARTYPE == eType || HIGH_CHARTYPE == eType )
+//		if( LOW_CHARTYPE == eType || HIGH_CHARTYPE == eType )	//Takashi Ono for CJK
+		if( LOW_CHARTYPE == eType )
 		{
 			if( *pNormal )
 			{
 				rItem.SetWhich( *pNormal );
+				rSet.Put( rItem );
+			}
+		}
+		else if( HIGH_CHARTYPE == eType )
+		{
+			if( *pCTL )
+			{
+				rItem.SetWhich( *pCTL );
 				rSet.Put( rItem );
 			}
 		}
