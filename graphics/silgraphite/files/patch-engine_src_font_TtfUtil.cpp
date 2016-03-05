--- engine/src/font/TtfUtil.cpp.orig	2009-01-29 08:33:19 UTC
+++ engine/src/font/TtfUtil.cpp
@@ -1106,7 +1106,7 @@ size_t LocaLookup(gr::gid16 nGlyphId, 
 	// CheckTable verifies the index_to_loc_format is valid
 	if (read(pTable->index_to_loc_format) == Sfnt::FontHeader::ShortIndexLocFormat)
 	{ // loca entries are two bytes and have been divided by two
-		if (nGlyphId <= (lLocaSize >> 1) - 1) // allow sentinel value to be accessed
+		if (lLocaSize >= 2 && nGlyphId <= (lLocaSize >> 1) - 1) // allow sentinel value to be accessed
 		{
 			const uint16 * pTable = reinterpret_cast<const uint16 *>(pLoca);
 			return (read(pTable[nGlyphId]) << 1);
@@ -1115,7 +1115,7 @@ size_t LocaLookup(gr::gid16 nGlyphId, 
 	
 	if (read(pTable->index_to_loc_format) == Sfnt::FontHeader::LongIndexLocFormat)
 	{ // loca entries are four bytes
-		if (nGlyphId <= (lLocaSize >> 2) - 1)
+		if (lLocaSize >= 4 && nGlyphId <= (lLocaSize >> 2) - 1)
 		{
 			const uint32 * pTable = reinterpret_cast<const uint32 *>(pLoca);
 			return read(pTable[nGlyphId]);
