From 0d301779bd42da52b4f8e13a667499846fc2cc55 Mon Sep 17 00:00:00 2001
From: Reini Urban <rurban@cpanel.net>
Date: Tue, 14 Jun 2016 17:08:24 +0200
Subject: [PATCH] Fix 5.25 or 5.22/24 with PERL_OP_PARENT

Fixes RT #114490
--- lib/Params/Classify.xs.orig	2010-11-16 20:35:47 UTC
+++ lib/Params/Classify.xs
@@ -123,6 +123,22 @@ static void *THX_ptr_table_fetch(pTHX_ P
 # define sv_is_regexp(sv) 0
 #endif /* <5.11.0 */
 
+
+#ifndef OpSIBLING
+# ifdef PERL_OP_PARENT
+#  define OpSIBLING(o)		(0 + (o)->op_moresib ? (o)->op_sibparent : NULL)
+#  define OpMAYBESIB_set(o, sib, parent) \
+       ((o)->op_sibparent = ((o)->op_moresib = cBOOL(sib)) ? (sib) : (parent))
+# else
+#  define OpSIBLING(o)		(0 + (o)->op_sibling)
+#  if PERL_VERSION_GE(5,11,0)
+#    define OpMAYBESIB_set(o, sib, parent) ((o)->op_sibling = (sib))
+#  else
+#    define OpMAYBESIB_set(o, sib, parent) ((o)->op_moresib = cBOOL(sib), (o)->op_sibling = (sib))
+#  endif
+# endif
+#endif
+
 #define sv_is_undef(sv) (!sv_is_glob(sv) && !sv_is_regexp(sv) && !SvOK(sv))
 
 #define sv_is_string(sv) \
@@ -625,8 +641,8 @@ static OP *myck_entersub(pTHX_ OP *op)
 	OP *(*ppfunc)(pTHX);
 	I32 cvflags;
 	pushop = cUNOPx(op)->op_first;
-	if(!pushop->op_sibling) pushop = cUNOPx(pushop)->op_first;
-	for(cvop = pushop; cvop->op_sibling; cvop = cvop->op_sibling) ;
+	if(!OpSIBLING(pushop)) pushop = cUNOPx(pushop)->op_first;
+	for(cvop = pushop; OpSIBLING(cvop); cvop = OpSIBLING(cvop)) ;
 	if(!(cvop->op_type == OP_RV2CV &&
 			!(cvop->op_private & OPpENTERSUB_AMPER) &&
 			(cv = rvop_cv(cUNOPx(cvop)->op_first)) &&
@@ -635,20 +651,20 @@ static OP *myck_entersub(pTHX_ OP *op)
 		return nxck_entersub(aTHX_ op);
 	cvflags = CvXSUBANY(cv).any_i32;
 	op = nxck_entersub(aTHX_ op);   /* for prototype checking */
-	aop = pushop->op_sibling;
-	bop = aop->op_sibling;
+	aop = OpSIBLING(pushop);
+	bop = OpSIBLING(aop);
 	if(bop == cvop) {
 		if(!(cvflags & PC_ALLOW_UNARY)) return op;
 		unary:
-		pushop->op_sibling = bop;
-		aop->op_sibling = NULL;
+		OpMAYBESIB_set(pushop, bop, NULL);
+		OpMAYBESIB_set(aop, NULL, NULL);
 		op_free(op);
 		op = newUNOP(OP_NULL, 0, aop);
 		op->op_type = OP_RAND;
 		op->op_ppaddr = ppfunc;
 		op->op_private = (U8)cvflags;
 		return op;
-	} else if(bop && bop->op_sibling == cvop) {
+	} else if(bop && OpSIBLING(bop) == cvop) {
 		if(!(cvflags & PC_ALLOW_BINARY)) return op;
 		if(ppfunc == THX_pp_check_sclass &&
 				(cvflags & PC_TYPE_MASK) == SCLASS_REF) {
@@ -667,9 +683,9 @@ static OP *myck_entersub(pTHX_ OP *op)
 			cvflags &= ~PC_TYPE_MASK;
 			ppfunc = THX_pp_check_dyn_battr;
 		}
-		pushop->op_sibling = cvop;
-		aop->op_sibling = NULL;
-		bop->op_sibling = NULL;
+		OpMAYBESIB_set(pushop, cvop, NULL);
+		OpMAYBESIB_set(aop, NULL, NULL);
+		OpMAYBESIB_set(bop, NULL, NULL);
 		op_free(op);
 		op = newBINOP(OP_NULL, 0, aop, bop);
 		op->op_type = OP_RAND;
