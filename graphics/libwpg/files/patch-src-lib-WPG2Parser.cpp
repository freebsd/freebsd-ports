--- src/lib/WPG2Parser.cpp
+++ src/lib/WPG2Parser.cpp
@@ -820,7 +820,7 @@ void WPG2Parser::handleDPPenForeColor()
 	unsigned char red = (m_doublePrecision)   ? readU16()>>8 : readU8();
 	unsigned char green = (m_doublePrecision) ? readU16()>>8 : readU8();
 	unsigned char blue = (m_doublePrecision)  ? readU16()>>8 : readU8();
-	unsigned char alpha = 0xff - (m_doublePrecision) ? readU16()>>8 : readU8();
+	unsigned char alpha = 0xff - ((m_doublePrecision) ? readU16()>>8 : readU8());
 
 	m_style.insert("svg:stroke-color", libwpg::WPGColor(red, green, blue, alpha).getColorString());
 	m_style.insert("svg:stroke-opacity", libwpg::WPGColor(red, green, blue, alpha).getOpacity(), WPX_PERCENT);
@@ -860,7 +860,7 @@ void WPG2Parser::handleDPPenBackColor()
 	unsigned int red = (m_doublePrecision)   ? readU16()>>8 : readU8();
 	unsigned int green = (m_doublePrecision) ? readU16()>>8 : readU8();
 	unsigned int blue = (m_doublePrecision)  ? readU16()>>8 : readU8();
-	unsigned int alpha = 0xff - (m_doublePrecision) ? readU16()>>8 : readU8();
+	unsigned int alpha = 0xff - ((m_doublePrecision) ? readU16()>>8 : readU8());
 
 	m_penBackColor = libwpg::WPGColor(red, green, blue, alpha);
 
@@ -1156,7 +1156,7 @@ void WPG2Parser::handleDPBrushForeColor()
 		unsigned char red = (m_doublePrecision)   ? readU16()>>8 : readU8();
 		unsigned char green = (m_doublePrecision)   ? readU16()>>8 : readU8();
 		unsigned char blue = (m_doublePrecision)   ? readU16()>>8 : readU8();
-		unsigned char alpha = 0xff - (m_doublePrecision)   ? readU16()>>8 : readU8();
+		unsigned char alpha = 0xff - ((m_doublePrecision)   ? readU16()>>8 : readU8());
 		WPG_DEBUG_MSG(("   Foreground color (RGBA): %d %d %d %d\n", red, green, blue, alpha));
 
 		m_brushForeColor = libwpg::WPGColor(red, green, blue, alpha);
@@ -1181,7 +1181,7 @@ void WPG2Parser::handleDPBrushForeColor()
 				unsigned char red = (m_doublePrecision)   ? readU16()>>8 : readU8();
 				unsigned char green = (m_doublePrecision)   ? readU16()>>8 : readU8();
 				unsigned char blue = (m_doublePrecision)   ? readU16()>>8 : readU8();
-				unsigned char alpha = 0xff - (m_doublePrecision)   ? readU16()>>8 : readU8();
+				unsigned char alpha = 0xff - ((m_doublePrecision)   ? readU16()>>8 : readU8());
 				libwpg::WPGColor color(red, green, blue, alpha);
 				colors.push_back(color);
 				WPG_DEBUG_MSG(("   Color #%d (RGBA): %d %d %d %d\n", i+1, red, green, blue, alpha));
