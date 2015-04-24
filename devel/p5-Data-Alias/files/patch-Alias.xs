--- Alias.xs.orig	2013-09-21 15:02:59 UTC
+++ Alias.xs
@@ -133,6 +133,15 @@
 #define op_lvalue(o, t) mod(o, t)
 #endif
 
+#ifndef IS_PADGV
+#define IS_PADGV(x) 0
+#endif
+
+#ifndef PadnamelistARRAY
+#define PadnamelistARRAY AvARRAY
+#define PadnameOUTER SvFAKE
+#endif
+
 #define DA_HAVE_OP_PADRANGE (PERL_COMBI_VERSION >= 5017006)
 
 #if DA_HAVE_OP_PADRANGE
@@ -221,6 +230,8 @@ static char const msg_no_symref[] =
 
 STATIC OP *(*da_old_ck_rv2cv)(pTHX_ OP *op);
 STATIC OP *(*da_old_ck_entersub)(pTHX_ OP *op);
+STATIC OP *(*da_old_ck_aelem)(pTHX_ OP *op);
+STATIC OP *(*da_old_ck_helem)(pTHX_ OP *op);
 
 #ifdef USE_ITHREADS
 
@@ -1485,7 +1496,9 @@ STATIC OP *DataAlias_pp_copy(pTHX) {
 STATIC void da_lvalue(pTHX_ OP *op, int list) {
 	switch (op->op_type) {
 	case OP_PADSV:     op->op_ppaddr = DataAlias_pp_padsv;
-			   if (SvFAKE(AvARRAY(PL_comppad_name)[op->op_targ])
+			   if (PadnameOUTER(
+				PadnamelistARRAY(PL_comppad_name)
+					[op->op_targ])
 					   && ckWARN(WARN_CLOSURE))
 				   Perl_warner(aTHX_ packWARN(WARN_CLOSURE),
 						   DA_OUTER_ERR);
@@ -1497,7 +1510,8 @@ STATIC void da_lvalue(pTHX_ OP *op, int 
 		int i;
 		if (!list) goto bad;
 		for(i = start; i != start+count; i++) {
-			   if (SvFAKE(AvARRAY(PL_comppad_name)[i])
+			   if (PadnameOUTER(
+				PadnamelistARRAY(PL_comppad_name)[i])
 					   && ckWARN(WARN_CLOSURE))
 				   Perl_warner(aTHX_ packWARN(WARN_CLOSURE),
 						   DA_OUTER_ERR);
@@ -1704,6 +1718,7 @@ STATIC int da_transform(pTHX_ OP *op, in
 			break;
 		case OP_AASSIGN:
 			op->op_ppaddr = DataAlias_pp_aassign;
+			op->op_type = OP_CUSTOM;
 			da_aassign(op, kid);
 			MOD(kid);
 			ksib = FALSE;
@@ -1780,7 +1795,7 @@ STATIC int da_transform(pTHX_ OP *op, in
 }
 
 STATIC void da_peep2(pTHX_ OP *o) {
-	OP *sib, *k;
+	OP *sib, *k, *o2;
 	int useful;
 	while (o->op_ppaddr != da_tag_list) {
 		while ((sib = o->op_sibling)) {
@@ -1800,13 +1815,20 @@ STATIC void da_peep2(pTHX_ OP *o) {
 	useful = o->op_private & OPpUSEFUL;
 	op_null(o);
 	o->op_ppaddr = PL_ppaddr[OP_NULL];
-	k = o = cLISTOPo->op_first;
+	k = o2 = cLISTOPo->op_first;
 	while ((sib = k->op_sibling))
 		k = sib;
-	if (!(sib = cUNOPo->op_first) || sib->op_ppaddr != da_tag_rv2cv) {
+	if (!(sib = cUNOPx(o2)->op_first)
+	 || sib->op_ppaddr != da_tag_rv2cv)
+	{
 		Perl_warn(aTHX_ "da peep weirdness 1");
 	} else {
+#ifdef op_sibling_splice
+		op_sibling_splice(o, k, 0, sib);
+#else
+		cLISTOPo->op_last = sib;
 		k->op_sibling = sib;
+#endif
 		if (!(k = sib->op_next) || k->op_ppaddr != da_tag_entersub) {
 			Perl_warn(aTHX_ "da peep weirdness 2");
 		} else {
@@ -1859,7 +1881,9 @@ STATIC OP *da_ck_rv2cv(pTHX_ OP *o) {
 		return o; /* not lexing? */
 	kid = cUNOPo->op_first;
 	if (kid->op_type != OP_GV || !DA_ACTIVE || (
-			(cv = GvCV(kGVOP_gv)) != da_cv && cv != da_cvc ))
+		(cv = SvROK(kGVOP_gv)
+			? (CV *)SvRV(kGVOP_gv)
+			: GvCV(kGVOP_gv)) != da_cv && cv != da_cvc ))
 		return o;
 	if (o->op_private & OPpENTERSUB_AMPER)
 		return o;
@@ -1900,8 +1924,9 @@ STATIC OP *da_ck_rv2cv(pTHX_ OP *o) {
 		if ((PL_nexttype[PL_nexttoke++] = yylex()) == '{') {
 			PL_nexttype[PL_nexttoke++] = DO;
 			sv_setpv((SV *) cv, "$");
-			if (PERL_COMBI_VERSION >= 5011002 &&
-					*PL_bufptr == '(') {
+			if ((PERL_COMBI_VERSION >= 5011002 &&
+					*PL_bufptr == '(')
+			   || PERL_COMBI_VERSION >= 5021004) {
 				/*
 				 * A paren here triggers special lexer
 				 * behaviour for a parenthesised argument
@@ -1910,6 +1935,10 @@ STATIC OP *da_ck_rv2cv(pTHX_ OP *o) {
 				 * Suppress it by injecting a semicolon,
 				 * which is otherwise a no-op coming just
 				 * after the opening brace of a block.
+				 * Also inject the semicolon for 5.21.4
+				 * and higher, because our setting of
+				 * PL_expect is undone, as PL_lex_expect
+				 * is not used any more.
 				 */
 				Move(PL_bufptr, PL_bufptr+1,
 					PL_bufend+1-PL_bufptr, char);
@@ -1920,7 +1949,9 @@ STATIC OP *da_ck_rv2cv(pTHX_ OP *o) {
 		}
 		if(PL_lex_state != LEX_KNOWNEXT) {
 			PL_lex_defer = PL_lex_state;
+#if PERL_COMBI_VERSION < 5021004
 			PL_lex_expect = PL_expect;
+#endif
 			PL_lex_state = LEX_KNOWNEXT;
 		}
 		PL_yylval = yylval;
@@ -1990,6 +2021,9 @@ STATIC OP *da_ck_entersub(pTHX_ OP *o) {
 		kid->op_private |= OPpUSEFUL;
 	else
 		kid->op_private &= ~OPpUSEFUL;
+	/* Defeat list+pushmark optimisation from v5.21.5-9-g6aa6830.  */
+	assert(kUNOP->op_first->op_type == OP_PUSHMARK);
+	kUNOP->op_first->op_type = OP_CUSTOM;
 	tmp = kLISTOP->op_first;
 	if (inside)
 		op_null(tmp);
@@ -2001,6 +2035,13 @@ STATIC OP *da_ck_entersub(pTHX_ OP *o) {
 	while (kid->op_sibling != last)
 		kid = kid->op_sibling;
 	kid->op_sibling = Nullop;
+#ifdef op_sibling_splice
+#if (PERL_COMBI_VERSION >= 5021011)
+	kid->op_moresib = 0;
+#else
+	kid->op_lastsib = 1;
+#endif
+#endif
 	cLISTOPx(cUNOPo->op_first)->op_last = kid;
 	if (kid->op_type == OP_NULL && inside)
 		kid->op_flags &= ~OPf_SPECIAL;
@@ -2008,6 +2049,14 @@ STATIC OP *da_ck_entersub(pTHX_ OP *o) {
 	return o;
 }
 
+/* These two exist solely to defeat the multideref optimisation.  */
+STATIC OP *da_ck_aelem(pTHX_ OP *o) {
+	return da_old_ck_aelem(aTHX_ o);
+}
+STATIC OP *da_ck_helem(pTHX_ OP *o) {
+	return da_old_ck_helem(aTHX_ o);
+}
+
 
 MODULE = Data::Alias  PACKAGE = Data::Alias
 
@@ -2025,6 +2074,10 @@ BOOT:
 		PL_check[OP_RV2CV] = da_ck_rv2cv;
 		da_old_ck_entersub = PL_check[OP_ENTERSUB];
 		PL_check[OP_ENTERSUB] = da_ck_entersub;
+		da_old_ck_aelem = PL_check[OP_AELEM];
+		PL_check[OP_AELEM] = da_ck_aelem;
+		da_old_ck_helem = PL_check[OP_HELEM];
+		PL_check[OP_HELEM] = da_ck_helem;
 	}
 	CvLVALUE_on(get_cv("Data::Alias::deref", TRUE));
 	da_old_peepp = PL_peepp;
