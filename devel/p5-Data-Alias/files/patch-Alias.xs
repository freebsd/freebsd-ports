--- Alias.xs
+++ Alias.xs
@@ -75,6 +75,10 @@
 #define SvPVX_const SvPVX
 #endif
 
+#if (PERL_COMBI_VERSION >= 5011000)
+#define SVt_RV SVt_IV
+#endif
+
 #ifndef SvREFCNT_inc_NN
 #define SvREFCNT_inc_NN SvREFCNT_inc
 #endif
@@ -366,7 +370,7 @@ STATIC void da_localize_gvar(pTHX_ GP *gp, SV **sptr) {
 	SSPUSHPTR(gp);
 	SSPUSHINT(SAVEt_DESTRUCTOR_X);
 	++gp->gp_refcnt;
-	*sptr = Nullsv;
+	*sptr = NULL;
 }
 
 STATIC SV *da_refgen(pTHX_ SV *sv) {
@@ -1248,7 +1252,7 @@ OP *DataAlias_pp_return(pTHX) {
 		cxstack_ix--;
 		POPSUB(cx, sv);
 	} else {
-		sv = Nullsv;
+		sv = NULL;
 	}
 	PL_curpm = newpm;
 	LEAVESUB(sv);
@@ -1433,7 +1437,7 @@ STATIC int da_transform(pTHX_ OP *op, int sib) {
 	int hits = 0;
 
 	while (op) {
-		OP *kid = Nullop, *tmp;
+		OP *kid = NULL, *tmp;
 		int ksib = TRUE;
 		OPCODE optype;
 
@@ -1447,7 +1451,9 @@ STATIC int da_transform(pTHX_ OP *op, int sib) {
 		default:
 			--hits;
 			switch (optype) {
+#if PERL_COMBI_VERSION < 5006000
 			case OP_SETSTATE:
+#endif
 			case OP_NEXTSTATE:
 			case OP_DBSTATE:
 				PL_curcop = (COP *) op;
@@ -1586,7 +1592,9 @@ STATIC int da_peep2(pTHX_ OP *o) {
 				if (da_peep2(aTHX_ k))
 					return 1;
 			} else switch (o->op_type ? o->op_type : o->op_targ) {
+#if PERL_COMBI_VERSION < 5006000
 			case OP_SETSTATE:
+#endif
 			case OP_NEXTSTATE:
 			case OP_DBSTATE:
 				PL_curcop = (COP *) o;
@@ -1764,7 +1772,7 @@ STATIC OP *da_ck_entersub(pTHX_ OP *o) {
 	kUNOP->op_first = last;
 	while (kid->op_sibling != last)
 		kid = kid->op_sibling;
-	kid->op_sibling = Nullop;
+	kid->op_sibling = NULL;
 	cLISTOPx(cUNOPo->op_first)->op_last = kid;
 	if (kid->op_type == OP_NULL && inside)
 		kid->op_flags &= ~OPf_SPECIAL;
