--- src/af/xap/xp/xap_Draw_Symbol.cpp.orig	Wed Jul 30 01:04:34 2003
+++ src/af/xap/xp/xap_Draw_Symbol.cpp	Wed Jul 30 01:07:18 2003
@@ -153,7 +153,7 @@
 	
 	for (i = 0; i < m_vCharSet.size(); i += 2)
 	{
-		UT_UCSChar base = static_cast<UT_UCSChar>(reinterpret_cast<UT_uint32>(m_vCharSet[i]));
+		UT_UCSChar base = static_cast<UT_UCSChar>(reinterpret_cast<unsigned long>(m_vCharSet[i]));
 		size_t nb_chars = reinterpret_cast<size_t>(m_vCharSet[i + 1]);
 
 		for (UT_UCSChar j = base; j < base + nb_chars; ++j)
@@ -194,11 +194,11 @@
 	UT_DEBUGMSG(("calcSymbolFromCoords(x = [%u], y = [%u]) =", ix, iy));
 	for (size_t i = 0; i < m_vCharSet.size(); i += 2)
 	{
-		count += reinterpret_cast<UT_uint32>(m_vCharSet[i + 1]);
+		count += static_cast<UT_uint32>(reinterpret_cast<unsigned long>(m_vCharSet[i + 1]));
 		if (count > index)
 		{
 			UT_DEBUGMSG((" %u\n", static_cast<UT_uint32>(reinterpret_cast<UT_uint32>(m_vCharSet[i]) + index - count + reinterpret_cast<UT_uint32>(m_vCharSet[i + 1]))));
-			return static_cast<UT_UCSChar>(reinterpret_cast<UT_uint32>(m_vCharSet[i]) + index - count + reinterpret_cast<UT_uint32>(m_vCharSet[i + 1]));
+			return static_cast<UT_UCSChar>(static_cast<UT_uint32>(reinterpret_cast<unsigned long>(m_vCharSet[i])) + index - count + static_cast<UT_uint32>(reinterpret_cast<unsigned long>(m_vCharSet[i + 1])));
 		}
 	}
 
@@ -227,8 +227,8 @@
 
 	for (size_t i = 0; i < m_vCharSet.size(); i += 2)
 	{
-		UT_uint32 base = reinterpret_cast<UT_uint32>(m_vCharSet[i]);
-		UT_uint32 size = reinterpret_cast<UT_uint32>(m_vCharSet[i + 1]);
+		UT_uint32 base = static_cast<UT_uint32>(reinterpret_cast<unsigned long>(m_vCharSet[i]));
+		UT_uint32 size = static_cast<UT_uint32>(reinterpret_cast<unsigned long>(m_vCharSet[i + 1]));
 		
 		if (base + size > c)
 		{
