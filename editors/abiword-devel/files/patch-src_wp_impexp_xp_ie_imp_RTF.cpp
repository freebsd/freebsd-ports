--- src/wp/impexp/xp/ie_imp_RTF.cpp.orig	Tue Sep 23 21:19:45 2003
+++ src/wp/impexp/xp/ie_imp_RTF.cpp	Tue Sep 23 21:22:22 2003
@@ -1208,9 +1208,9 @@
 		m_iOverrideLevel = other.m_iOverrideLevel;
 		if(m_tabTypes.getItemCount() > 0)
 		{
-			UT_uint32 dum = reinterpret_cast<UT_uint32>(m_tabTypes.getNthItem(0));
+			UT_uint32 dum = reinterpret_cast<unsigned long>(m_tabTypes.getNthItem(0));
 			m_curTabType = static_cast<eTabType>(dum);
-			dum = reinterpret_cast<UT_uint32>(m_tabLeader.getNthItem(0));
+			dum = reinterpret_cast<unsigned long>(m_tabLeader.getNthItem(0));
 			m_curTabLeader = static_cast<eTabLeader>(dum);
 		}
 		else
@@ -2442,7 +2442,7 @@
 {
 	if (colNum < m_colourTable.getItemCount())
 	{
-		return reinterpret_cast<UT_uint32>(m_colourTable.getNthItem(colNum));
+		return reinterpret_cast<unsigned long>(m_colourTable.getNthItem(colNum));
 	}
 	else
 	{
@@ -2454,7 +2454,7 @@
 {
 	if (colNum < m_colourTable.getItemCount())
 	{
-		return reinterpret_cast<UT_sint32>(m_colourTable.getNthItem(colNum));
+		return reinterpret_cast<long>(m_colourTable.getNthItem(colNum));
 	}
 	else
 	{
@@ -6185,11 +6185,11 @@
 			if (i > 0)
 				propBuffer += ",";
 
-			UT_sint32 tabTwips = reinterpret_cast<UT_sint32>(m_currentRTFState.m_paraProps.m_tabStops.getNthItem(i));
+			UT_sint32 tabTwips = reinterpret_cast<long>(m_currentRTFState.m_paraProps.m_tabStops.getNthItem(i));
 			double tabIn = tabTwips/(20.0*72.);
-			UT_uint32 idum = reinterpret_cast<UT_uint32>(m_currentRTFState.m_paraProps.m_tabTypes.getNthItem(i));
+			UT_uint32 idum = reinterpret_cast<unsigned long>(m_currentRTFState.m_paraProps.m_tabTypes.getNthItem(i));
 			eTabType tabType = static_cast<eTabType>(idum);
-			idum = reinterpret_cast<UT_uint32>((m_currentRTFState.m_paraProps.m_tabLeader.getNthItem(i)));
+			idum = reinterpret_cast<unsigned long>((m_currentRTFState.m_paraProps.m_tabLeader.getNthItem(i)));
 			eTabLeader tabLeader = static_cast<eTabLeader>(idum);
 			char  cType = ' ';
 			switch(tabType)
@@ -9654,9 +9654,9 @@
 		if (i > 0)
 			strcat(propBuffer, ",");
 
-		UT_sint32 tabTwips = reinterpret_cast<UT_sint32>(pParas->m_tabStops.getNthItem(i));
+		UT_sint32 tabTwips = reinterpret_cast<long>(pParas->m_tabStops.getNthItem(i));
 		double tabIn = tabTwips/(20.0*72.);
-		UT_uint32 idum = reinterpret_cast<UT_uint32>(pParas->m_tabTypes.getNthItem(i));
+		UT_uint32 idum = reinterpret_cast<unsigned long>(pParas->m_tabTypes.getNthItem(i));
 		eTabType tabType = static_cast<eTabType>(idum);
 		idum = (UT_uint32) (pParas->m_tabLeader.getNthItem(i));
 		eTabLeader tabLeader = static_cast<eTabLeader>(idum);
