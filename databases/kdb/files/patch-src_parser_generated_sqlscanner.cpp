The register keyword is reserved and unused in C++17.

--- src/parser/generated/sqlscanner.cpp.orig	2019-03-26 18:44:44 UTC
+++ src/parser/generated/sqlscanner.cpp
@@ -864,9 +864,9 @@ YY_DECL
  */
 YY_DECL
 {
-	register yy_state_type yy_current_state;
-	register char *yy_cp, *yy_bp;
-	register int yy_act;
+	yy_state_type yy_current_state;
+	char *yy_cp, *yy_bp;
+	int yy_act;
     
 #line 63 "KDbSqlScanner.l"
 
@@ -917,7 +917,7 @@ yy_match:
 yy_match:
 		do
 			{
-			register YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
+			YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
 			if ( yy_accept[yy_current_state] )
 				{
 				(yy_last_accepting_state) = yy_current_state;
@@ -1582,9 +1582,9 @@ static int yy_get_next_buffer (void)
  */
 static int yy_get_next_buffer (void)
 {
-    	register char *dest = YY_CURRENT_BUFFER_LVALUE->yy_ch_buf;
-	register char *source = (yytext_ptr);
-	register int number_to_move, i;
+    	char *dest = YY_CURRENT_BUFFER_LVALUE->yy_ch_buf;
+	char *source = (yytext_ptr);
+	int number_to_move, i;
 	int ret_val;
 
 	if ( (yy_c_buf_p) > &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars) + 1] )
@@ -1716,14 +1716,14 @@ static int yy_get_next_buffer (void)
 
     static yy_state_type yy_get_previous_state (void)
 {
-	register yy_state_type yy_current_state;
-	register char *yy_cp;
+	yy_state_type yy_current_state;
+	char *yy_cp;
     
 	yy_current_state = (yy_start);
 
 	for ( yy_cp = (yytext_ptr) + YY_MORE_ADJ; yy_cp < (yy_c_buf_p); ++yy_cp )
 		{
-		register YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
+		YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
 		if ( yy_accept[yy_current_state] )
 			{
 			(yy_last_accepting_state) = yy_current_state;
@@ -1748,10 +1748,10 @@ static int yy_get_next_buffer (void)
  */
     static yy_state_type yy_try_NUL_trans  (yy_state_type yy_current_state )
 {
-	register int yy_is_jam;
-    	register char *yy_cp = (yy_c_buf_p);
+	int yy_is_jam;
+    	char *yy_cp = (yy_c_buf_p);
 
-	register YY_CHAR yy_c = 1;
+	YY_CHAR yy_c = 1;
 	if ( yy_accept[yy_current_state] )
 		{
 		(yy_last_accepting_state) = yy_current_state;
@@ -1769,9 +1769,9 @@ static int yy_get_next_buffer (void)
 		return yy_is_jam ? 0 : yy_current_state;
 }
 
-    static void yyunput (int c, register char * yy_bp )
+    static void yyunput (int c, char * yy_bp )
 {
-	register char *yy_cp;
+	char *yy_cp;
     
     yy_cp = (yy_c_buf_p);
 
@@ -1781,10 +1781,10 @@ static int yy_get_next_buffer (void)
 	if ( yy_cp < YY_CURRENT_BUFFER_LVALUE->yy_ch_buf + 2 )
 		{ /* need to shift things up to make room */
 		/* +2 for EOB chars. */
-		register int number_to_move = (yy_n_chars) + 2;
-		register char *dest = &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[
+		int number_to_move = (yy_n_chars) + 2;
+		char *dest = &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[
 					YY_CURRENT_BUFFER_LVALUE->yy_buf_size + 2];
-		register char *source =
+		char *source =
 				&YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[number_to_move];
 
 		while ( source > YY_CURRENT_BUFFER_LVALUE->yy_ch_buf )
@@ -2393,7 +2393,7 @@ static void yy_flex_strncpy (char* s1, yyconst char * 
 #ifndef yytext_ptr
 static void yy_flex_strncpy (char* s1, yyconst char * s2, int n )
 {
-	register int i;
+	int i;
 	for ( i = 0; i < n; ++i )
 		s1[i] = s2[i];
 }
@@ -2402,7 +2402,7 @@ static int yy_flex_strlen (yyconst char * s )
 #ifdef YY_NEED_STRLEN
 static int yy_flex_strlen (yyconst char * s )
 {
-	register int n;
+	int n;
 	for ( n = 0; s[n]; ++n )
 		;
 
