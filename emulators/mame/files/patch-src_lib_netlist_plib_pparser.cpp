--- src/lib/netlist/plib/pparser.cpp.orig	2018-02-27 15:59:06 UTC
+++ src/lib/netlist/plib/pparser.cpp
@@ -34,22 +34,22 @@ pstring ptokenizer::currentline_str()
 
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
-				ungetc(c);
+				mame_ungetc(c);
 			return;
 		}
-		c = getc();
+		c = mame_getc();
 	}
 }
 
 
-pstring::code_t ptokenizer::getc()
+pstring::code_t ptokenizer::mame_getc()
 {
 	if (m_unget != 0)
 	{
@@ -70,7 +70,7 @@ pstring::code_t ptokenizer::getc()
 	return c;
 }
 
-void ptokenizer::ungetc(pstring::code_t c)
+void ptokenizer::mame_ungetc(pstring::code_t c)
 {
 	m_unget = c;
 }
@@ -182,10 +182,10 @@ ptokenizer::token_t ptokenizer::get_toke
 ptokenizer::token_t ptokenizer::get_token_internal()
 {
 	/* skip ws */
-	pstring::code_t c = getc();
+	pstring::code_t c = mame_getc();
 	while (m_whitespace.find(c) != pstring::npos)
 	{
-		c = getc();
+		c = mame_getc();
 		if (eof())
 		{
 			return token_t(ENDOFFILE);
@@ -205,9 +205,9 @@ ptokenizer::token_t ptokenizer::get_toke
 			else if (m_number_chars.find(c) == pstring::npos)
 				break;
 			tokstr += c;
-			c = getc();
+			c = mame_getc();
 		}
-		ungetc(c);
+		mame_ungetc(c);
 		return token_t(ret, tokstr);
 	}
 	else if (m_identifier_chars.find(c) != pstring::npos)
@@ -217,9 +217,9 @@ ptokenizer::token_t ptokenizer::get_toke
 		while (m_identifier_chars.find(c) != pstring::npos)
 		{
 			tokstr += c;
-			c = getc();
+			c = mame_getc();
 		}
-		ungetc(c);
+		mame_ungetc(c);
 		auto id = m_tokens.find(tokstr);
 		if (id != m_tokens.end())
 			return token_t(id->second, tokstr);
@@ -229,11 +229,11 @@ ptokenizer::token_t ptokenizer::get_toke
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
@@ -251,9 +251,9 @@ ptokenizer::token_t ptokenizer::get_toke
 				if (id != m_tokens.end())
 					return token_t(id->second, tokstr);
 			}
-			c = getc();
+			c = mame_getc();
 		}
-		ungetc(c);
+		mame_ungetc(c);
 		auto id = m_tokens.find(tokstr);
 		if (id != m_tokens.end())
 			return token_t(id->second, tokstr);
