--- src/lib/netlist/plib/pparser.h.orig	2018-02-27 15:59:06 UTC
+++ src/lib/netlist/plib/pparser.h
@@ -118,8 +118,8 @@ protected:
 private:
 	void skipeol();
 
-	pstring::code_t getc();
-	void ungetc(pstring::code_t c);
+	pstring::code_t mame_getc();
+	void mame_ungetc(pstring::code_t c);
 
 	bool eof() { return m_strm.eof(); }
 
