--- src/commentscan.l.orig	2015-05-31 19:01:12 UTC
+++ src/commentscan.l
@@ -1103,7 +1103,7 @@ RCSTAG    "$"{ID}":"[^\n$]+"$"
 					      // but we need to know the position in the input buffer where this 
 					      // rule matched.
 					      // for flex 2.5.33+ we should use YY_CURRENT_BUFFER_LVALUE
-#if YY_FLEX_MINOR_VERSION>=5 && YY_FLEX_SUBMINOR_VERSION>=33
+#if YY_FLEX_MINOR_VERSION==5 && YY_FLEX_SUBMINOR_VERSION>=33 || YY_FLEX_MINOR_VERSION>=6
 					      inputPosition=prevPosition + (int)(yy_bp - YY_CURRENT_BUFFER_LVALUE->yy_ch_buf);
 #else
 					      inputPosition=prevPosition + (int)(yy_bp - yy_current_buffer->yy_ch_buf);
@@ -1165,7 +1165,7 @@ RCSTAG    "$"{ID}":"[^\n$]+"$"
                                           g_memberGroupHeader.resize(0);
 					  parseMore=TRUE;
                                           needNewEntry = TRUE;
-#if YY_FLEX_MINOR_VERSION>=5 && YY_FLEX_SUBMINOR_VERSION>=33
+#if YY_FLEX_MINOR_VERSION==5 && YY_FLEX_SUBMINOR_VERSION>=33 || YY_FLEX_MINOR_VERSION>=6
 				          inputPosition=prevPosition + (int)(yy_bp - YY_CURRENT_BUFFER_LVALUE->yy_ch_buf) + strlen(yytext);
 #else
 				          inputPosition=prevPosition + (int)(yy_bp - yy_current_buffer->yy_ch_buf) + strlen(yytext);
