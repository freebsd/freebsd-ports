--- src/lib/netlist/plib/pparser.h.orig	2015-09-30 06:29:01 UTC
+++ src/lib/netlist/plib/pparser.h
@@ -120,8 +120,8 @@ protected:
 private:
 	void skipeol();
 
-	pstring::code_t getc();
-	void ungetc();
+	pstring::code_t mame_getc();
+	void mame_ungetc();
 
 	bool eof() { return m_strm.eof(); }
 
