--- src/wp/impexp/xp/ie_Table.cpp.orig	Tue Sep 23 21:23:58 2003
+++ src/wp/impexp/xp/ie_Table.cpp	Tue Sep 23 21:31:58 2003
@@ -1028,7 +1028,7 @@
 			UT_sint32 j = 0;
 			for(j=0; !bMatch && (j < static_cast<UT_sint32>(m_vecCellX.getItemCount())); j++)
 			{
-				UT_sint32 prevX = reinterpret_cast<UT_sint32>(m_vecCellX.getNthItem(j));
+				UT_sint32 prevX = reinterpret_cast<long>(m_vecCellX.getNthItem(j));
 				UT_DEBUGMSG(("Prev cell %d cellx %d \n",j,prevX));
 				bool bLast = ((j-1) == szCurRow);
 				bMatch =  doCellXMatch(prevX,curX,bLast);
@@ -1179,7 +1179,7 @@
 		sColWidth.clear();
 		for(i=0; i< static_cast<UT_sint32>(m_vecCellX.getItemCount()); i++)
 		{
-			UT_sint32 iCellx = reinterpret_cast<UT_sint32>(m_vecCellX.getNthItem(i));
+			UT_sint32 iCellx = reinterpret_cast<long>(m_vecCellX.getNthItem(i));
 			xxx_UT_DEBUGMSG(("final cellx import cellx %d iPrev %x \n",iCellx,iPrev));
 			UT_sint32 iDiffCellx = iCellx - iPrev;
 			double dCellx = static_cast<double>(iDiffCellx)/1440.0 -dColSpace;
@@ -1377,7 +1377,7 @@
 	UT_sint32 iSub = 0;
 	for(i=0; !bFound && (i< static_cast<UT_sint32>(m_vecCellX.getItemCount())); i++)
 	{
-		UT_sint32 icellx = reinterpret_cast<UT_sint32>(m_vecCellX.getNthItem(i));
+		UT_sint32 icellx = reinterpret_cast<long>(m_vecCellX.getNthItem(i));
 		if(icellx == -1)
 		{
 			iSub++;
