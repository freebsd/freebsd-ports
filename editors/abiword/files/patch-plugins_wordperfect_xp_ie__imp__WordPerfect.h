--- plugins/wordperfect/xp/ie_imp_WordPerfect.h.orig	2013-04-07 15:53:03.000000000 +0200
+++ plugins/wordperfect/xp/ie_imp_WordPerfect.h	2016-01-26 20:42:39.167115000 +0100
@@ -30,7 +30,7 @@
 #define IE_IMP_WP_H
 
 #include <stdio.h>
-#include <libwpd/libwpd.h>
+#include <librevenge/librevenge.h>
 #include "ie_imp.h"
 #include "ut_string.h"
 #include "ut_string_class.h"
@@ -92,7 +92,7 @@ public:
 					IE_Imp ** ppie);
 };
 
-class IE_Imp_WordPerfect : public IE_Imp, public WPXDocumentInterface
+class IE_Imp_WordPerfect : public IE_Imp, public librevenge::RVNGTextInterface
 {
 public:
     IE_Imp_WordPerfect(PD_Document * pDocument);
@@ -101,68 +101,82 @@ public:
     virtual void pasteFromBuffer(PD_DocumentRange * pDocRange,
 				 UT_uint8 * pData, UT_uint32 lenData, const char * szEncoding = 0);
 
-    virtual void setDocumentMetaData(const WPXPropertyList &propList);
+	virtual void setDocumentMetaData(const librevenge::RVNGPropertyList &propList);
 
-    virtual void startDocument();
-    virtual void endDocument();
+	virtual void startDocument(const librevenge::RVNGPropertyList &propList);
+	virtual void endDocument();
 
-    virtual void openPageSpan(const WPXPropertyList &propList);
-    virtual void closePageSpan() {}
-    virtual void openHeader(const WPXPropertyList &propList);
-    virtual void closeHeader();
-    virtual void openFooter(const WPXPropertyList &propList);
-    virtual void closeFooter();
-
-    virtual void openParagraph(const WPXPropertyList &propList, const WPXPropertyListVector &tabStops);
-    virtual void closeParagraph() {}
-
-    virtual void openSpan(const WPXPropertyList &propList);
-    virtual void closeSpan() {}
-
-    virtual void openSection(const WPXPropertyList &propList, const WPXPropertyListVector &columns);
-    virtual void closeSection() {}
-
-    virtual void insertTab();
-    virtual void insertText(const WPXString &text);
-    virtual void insertLineBreak();
-
-    virtual void defineOrderedListLevel(const WPXPropertyList &propList);
-    virtual void defineUnorderedListLevel(const WPXPropertyList &propList);
-    virtual void openOrderedListLevel(const WPXPropertyList &propList);
-    virtual void openUnorderedListLevel(const WPXPropertyList &propList);
-    virtual void closeOrderedListLevel();
-    virtual void closeUnorderedListLevel();
-    virtual void openListElement(const WPXPropertyList &propList, const WPXPropertyListVector &tabStops);
-    virtual void closeListElement() {}
-
-    virtual void openFootnote(const WPXPropertyList &propList);
-    virtual void closeFootnote();
-    virtual void openEndnote(const WPXPropertyList &propList);
-    virtual void closeEndnote();
-
-    virtual void openTable(const WPXPropertyList &propList, const WPXPropertyListVector &columns);
-    virtual void openTableRow(const WPXPropertyList &propList);
-    virtual void closeTableRow() {}
-    virtual void openTableCell(const WPXPropertyList &propList);
-    virtual void closeTableCell() {}
-    virtual void insertCoveredTableCell(const WPXPropertyList & /*propList*/) {}
-    virtual void closeTable();
-
-    virtual void definePageStyle(const WPXPropertyList&) {}
-    virtual void defineParagraphStyle(const WPXPropertyList&, const WPXPropertyListVector&) {}
-    virtual void defineCharacterStyle(const WPXPropertyList&) {}
-    virtual void defineSectionStyle(const WPXPropertyList&, const WPXPropertyListVector&) {}
-    virtual void insertSpace() {}
-    virtual void insertField(const WPXString&, const WPXPropertyList&) {}
-    virtual void openComment(const WPXPropertyList&) {}
-    virtual void closeComment() {}
-    virtual void openTextBox(const WPXPropertyList&) {}
-    virtual void closeTextBox() {}
-    virtual void openFrame(const WPXPropertyList&) {}
-    virtual void closeFrame() {}
-    virtual void insertBinaryObject(const WPXPropertyList&, const WPXBinaryData&) {}
-    virtual void insertEquation(const WPXPropertyList&, const WPXString&) {}
+	virtual void defineEmbeddedFont(const librevenge::RVNGPropertyList & /* propList */) {}
 
+	virtual void definePageStyle(const librevenge::RVNGPropertyList &) {}
+	virtual void openPageSpan(const librevenge::RVNGPropertyList &propList);
+	virtual void closePageSpan() {}
+	virtual void openHeader(const librevenge::RVNGPropertyList &propList);
+	virtual void closeHeader();
+	virtual void openFooter(const librevenge::RVNGPropertyList &propList);
+	virtual void closeFooter();
+
+	virtual void defineSectionStyle(const librevenge::RVNGPropertyList &) {}
+	virtual void openSection(const librevenge::RVNGPropertyList &propList);
+	virtual void closeSection() {}
+
+	virtual void defineParagraphStyle(const librevenge::RVNGPropertyList &) {}
+	virtual void openParagraph(const librevenge::RVNGPropertyList &propList);
+	virtual void closeParagraph() {}
+
+	virtual void defineCharacterStyle(const librevenge::RVNGPropertyList &) {}
+	virtual void openSpan(const librevenge::RVNGPropertyList &propList);
+	virtual void closeSpan() {}
+
+	virtual void openLink(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void closeLink() {}
+
+	virtual void insertTab();
+	virtual void insertText(const librevenge::RVNGString &text);
+	virtual void insertSpace();
+	virtual void insertLineBreak();
+	virtual void insertField(const librevenge::RVNGPropertyList & /* propList */) {}
+
+	virtual void openOrderedListLevel(const librevenge::RVNGPropertyList &propList);
+	virtual void openUnorderedListLevel(const librevenge::RVNGPropertyList &propList);
+	virtual void closeOrderedListLevel();
+	virtual void closeUnorderedListLevel();
+	virtual void openListElement(const librevenge::RVNGPropertyList &propList);
+	virtual void closeListElement() {}
+
+	virtual void openFootnote(const librevenge::RVNGPropertyList &propList);
+	virtual void closeFootnote();
+	virtual void openEndnote(const librevenge::RVNGPropertyList &propList);
+	virtual void closeEndnote();
+	virtual void openComment(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void closeComment() {}
+	virtual void openTextBox(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void closeTextBox() {}
+
+	virtual void openTable(const librevenge::RVNGPropertyList &propList);
+	virtual void openTableRow(const librevenge::RVNGPropertyList &propList);
+	virtual void closeTableRow() {}
+	virtual void openTableCell(const librevenge::RVNGPropertyList &propList);
+	virtual void closeTableCell() {}
+	virtual void insertCoveredTableCell(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void closeTable();
+
+	virtual void openFrame(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void closeFrame() {}
+
+	virtual void openGroup(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void closeGroup() {}
+
+	virtual void defineGraphicStyle(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void drawRectangle(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void drawEllipse(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void drawPolygon(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void drawPolyline(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void drawPath(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void drawConnector(const librevenge::RVNGPropertyList & /* propList */) {}
+
+	virtual void insertBinaryObject(const librevenge::RVNGPropertyList & /* propList */) {}
+	virtual void insertEquation(const librevenge::RVNGPropertyList & /* propList */) {}
 
 protected:
 	virtual UT_Error _loadFile(GsfInput * input);
