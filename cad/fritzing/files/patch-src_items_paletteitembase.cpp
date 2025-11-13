--- src/items/paletteitembase.cpp.orig	2025-04-02 10:33:24 UTC
+++ src/items/paletteitembase.cpp
@@ -626,7 +626,7 @@ QString PaletteItemBase::retrieveSvg(ViewLayer::ViewLa
 
 	//DebugDialog::debug(QString("path: %1").arg(path));
 
-	QString svg = svgHash.value(path + xmlName + QString(QChar(m_viewLayerPlacement)), "");
+	QString svg = svgHash.value(path + xmlName + QString(QChar(static_cast<int>(m_viewLayerPlacement))), "");
 	if (!svg.isEmpty()) return svg;
 
 	SvgFileSplitter splitter;
@@ -657,7 +657,7 @@ QString PaletteItemBase::retrieveSvg(ViewLayer::ViewLa
 		return "";
 	}
 	svg = splitter.elementString(xmlName);
-	svgHash.insert(path + xmlName + QString(QChar(m_viewLayerPlacement)), svg);
+	svgHash.insert(path + xmlName + QString(QChar(static_cast<int>(m_viewLayerPlacement))), svg);
 	return svg;
 }
 
