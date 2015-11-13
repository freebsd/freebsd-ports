--- src/lib/netlist/plib/pparser.c.orig	2015-09-30 06:29:01 UTC
+++ src/lib/netlist/plib/pparser.c
@@ -28,22 +28,22 @@ pstring ptokenizer::currentline_str()
 
 void ptokenizer::skipeol()
 {
-	pstring::code_t c = getc();
+	pstring::code_t c = mame_getc();
 	while (c)
 	{
 		if (c == 10)
 		{
-			c = getc();
+			c = mame_getc();
 			if (c != 13)
-				ungetc();
+				mame_ungetc();
 			return;
 		}
-		c = getc();
+		c = mame_getc();
 	}
 }
 
 
-pstring::code_t ptokenizer::getc()
+pstring::code_t ptokenizer::mame_getc()
 {
 	if (m_px >= m_cur_line.len())
 	{
@@ -58,7 +58,7 @@ pstring::code_t ptokenizer::getc()
 	return m_cur_line.code_at(m_px++);
 }
 
-void ptokenizer::ungetc()
+void ptokenizer::mame_ungetc()
 {
 	m_px--;
 }
@@ -166,10 +166,10 @@ ptokenizer::token_t ptokenizer::get_toke
 ptokenizer::token_t ptokenizer::get_token_internal()
 {
 	/* skip ws */
-	pstring::code_t c = getc();
+	pstring::code_t c = mame_getc();
 	while (m_whitespace.find(c)>=0)
 	{
-		c = getc();
+		c = mame_getc();
 		if (eof())
 		{
 			return token_t(ENDOFFILE);
@@ -189,9 +189,9 @@ ptokenizer::token_t ptokenizer::get_toke
 			else if (m_number_chars.find(c)<0)
 				break;
 			tokstr += c;
-			c = getc();
+			c = mame_getc();
 		}
-		ungetc();
+		mame_ungetc();
 		return token_t(ret, tokstr);
 	}
 	else if (m_identifier_chars.find(c)>=0)
@@ -200,9 +200,9 @@ ptokenizer::token_t ptokenizer::get_toke
 		pstring tokstr = "";
 		while (m_identifier_chars.find(c)>=0) {
 			tokstr += c;
-			c = getc();
+			c = mame_getc();
 		}
-		ungetc();
+		mame_ungetc();
 		token_id_t id = token_id_t(m_tokens.indexof(tokstr));
 		if (id.id() >= 0)
 			return token_t(id, tokstr);
@@ -214,11 +214,11 @@ ptokenizer::token_t ptokenizer::get_toke
 	else if (c == m_string)
 	{
 		pstring tokstr = "";
-		c = getc();
+		c = mame_getc();
 		while (c != m_string)
 		{
 			tokstr += c;
-			c = getc();
+			c = mame_getc();
 		}
 		return token_t(STRING, tokstr);
 	}
@@ -235,9 +235,9 @@ ptokenizer::token_t ptokenizer::get_toke
 				if (id.id() >= 0)
 					return token_t(id, tokstr);
 			}
-			c = getc();
+			c = mame_getc();
 		}
-		ungetc();
+		mame_ungetc();
 		token_id_t id = token_id_t(m_tokens.indexof(tokstr));
 		if (id.id() >= 0)
 			return token_t(id, tokstr);
