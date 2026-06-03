--- src/extension/internal/pdfinput/poppler-utils.h.orig	2025-12-26 00:35:50 UTC
+++ src/extension/internal/pdfinput/poppler-utils.h
@@ -83,6 +83,7 @@ std::string getDictString(Dict *dict, const char *key)
 FontList getPdfFonts(std::shared_ptr<PDFDoc> pdf_doc);
 std::string getNameWithoutSubsetTag(std::string name);
 std::string getDictString(Dict *dict, const char *key);
+std::string getString(const std::string &value);
 std::string getString(const GooString *value);
 std::string validateString(std::string const &in);
 
