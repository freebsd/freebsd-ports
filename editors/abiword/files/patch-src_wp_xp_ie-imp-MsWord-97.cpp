--- src/wp/impexp/xp/ie_imp_MsWord_97.cpp.orig	2008-04-18 23:12:21.000000000 +0200
+++ src/wp/impexp/xp/ie_imp_MsWord_97.cpp	2009-03-25 10:50:53.000000000 +0100
@@ -354,6 +354,7 @@ typedef enum {
 	F_TOC_FROM_RANGE,
 	F_DATEINAME,
 	F_SPEICHERDAT,
+	F_MERGEFIELD,
 	F_OTHER
 } Doc_Field_t;
 
@@ -399,7 +400,7 @@ static Doc_Field_Mapping_t s_Tokens[] =
 	{"NUMCHARS",   F_NUMCHARS},
 	{"NUMPAGES",   F_NUMPAGES},
 	{"NUMWORDS",   F_NUMWORDS},
-
+	{"MERGEFIELD", F_MERGEFIELD},
 	// these below aren't handled by AbiWord, but they're known about
 	{"HYPERLINK",  F_HYPERLINK},
 	{"PAGEREF",    F_PAGEREF},
@@ -3336,7 +3337,7 @@ int IE_Imp_MsWord_97::_beginChar (wvPars
 		// inserting a symbol char ...
 		iFontType = ps->fonts.ffn[achp->ftcSym].chs;
 	}
-	else if(ps->fonts.ffn)
+	else if(ps->fonts.ffn && (achp->ftcAscii < ps->fonts.nostrings))
 	{
 		iFontType = ps->fonts.ffn[achp->ftcAscii].chs;
 	}
@@ -3637,6 +3638,49 @@ bool IE_Imp_MsWord_97::_handleFieldEnd (
 		tokenIndex = s_mapNameToField (token);
 		switch (tokenIndex)
 		{
+		    case F_MERGEFIELD:
+			{
+				const gchar* atts[5];
+				atts[0] = "type";
+				atts[1] = "mail_merge";
+				atts[2] = "param";
+				atts[3] = 0;
+				atts[4] = 0;
+
+				token = strtok (NULL, "\"\" ");
+
+				UT_return_val_if_fail(f->argument[f->fieldI - 1] == 0x15, false);
+				
+				f->argument[f->fieldI - 1] = 0;
+				UT_UCS2Char * a = f->argument;
+
+				UT_UTF8String param;
+				
+				if(*a == 0x14)
+					{
+						a++;
+					}
+
+				while(*a)
+					{
+						if (!((171 == *a) || (187 == *a))) {
+							// @argument looks like <<FieldName>>.
+							// strip off the '<<' (171) and '>>' (187)
+							param.appendUCS2(a, 1);
+						}
+
+						a++;
+					}
+
+				atts[3] = param.utf8_str();
+
+				if (!_appendObject (PTO_Field, static_cast<const gchar**>(&atts[0])))
+					{
+						UT_DEBUGMSG(("Dom: couldn't append field (type = '%s')\n", atts[1]));
+					}
+			}
+			break;
+
 			case F_HYPERLINK:
 				{
 					token = strtok (NULL, "\"\" ");
