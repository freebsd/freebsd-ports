--- src/drawlib/DrawLibOpenGL.cpp.orig	2011-10-12 00:18:26.000000000 +0400
+++ src/drawlib/DrawLibOpenGL.cpp	2014-11-24 22:08:12.925973647 +0300
@@ -80,7 +80,7 @@
   /* a glyph from other glyphs */
   /*kejo:why not just grrr create a copy contructor*/
   GLFontGlyph(const std::string& i_value,
-	      HashNamespace::hash_map<const char*, GLFontGlyphLetter*, HashNamespace::hash<const char*>, hashcmp_str>& i_glyphsLetters);
+	      HashNamespace::hash_map<std::string, GLFontGlyphLetter*>& i_glyphsLetters);
   virtual ~GLFontGlyph();
 
   std::string Value() const;
@@ -132,11 +132,11 @@
 private:
   std::vector<std::string> m_glyphsKeys;
   std::vector<GLFontGlyph*> m_glyphsValues;
-  HashNamespace::hash_map<const char*, GLFontGlyph*, HashNamespace::hash<const char*>, hashcmp_str> m_glyphs;
+  HashNamespace::hash_map<std::string, GLFontGlyph*> m_glyphs;
 
   std::vector<std::string> m_glyphsLettersKeys;
   std::vector<GLFontGlyphLetter*> m_glyphsLettersValues;
-  HashNamespace::hash_map<const char*, GLFontGlyphLetter*, HashNamespace::hash<const char*>, hashcmp_str> m_glyphsLetters;
+  HashNamespace::hash_map<std::string, GLFontGlyphLetter*> m_glyphsLetters;
 
   unsigned int getLonguestLineSize(const std::string& i_value, unsigned int i_start = 0, unsigned int i_nbLinesToRead = -1);
 };
@@ -825,7 +825,7 @@
 }
 
 GLFontGlyph::GLFontGlyph(const std::string& i_value,
-			 HashNamespace::hash_map<const char*, GLFontGlyphLetter*, HashNamespace::hash<const char*>, hashcmp_str>& i_glyphsLetters) {
+			 HashNamespace::hash_map<std::string, GLFontGlyphLetter*>& i_glyphsLetters) {
   GLFontGlyph* v_glyph;
   std::string  v_char;
 
