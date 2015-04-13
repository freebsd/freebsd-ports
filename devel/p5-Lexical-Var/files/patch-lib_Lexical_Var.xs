--- lib/Lexical/Var.xs.orig	2013-08-25 18:51:34 UTC
+++ lib/Lexical/Var.xs
@@ -62,7 +62,12 @@ typedef AV PAD;
 #endif /* !COP_SEQ_RANGE_LOW */
 
 #ifndef COP_SEQ_RANGE_LOW_set
-# if PERL_VERSION_GE(5,9,5)
+# ifdef newPADNAMEpvn
+#  define COP_SEQ_RANGE_LOW_set(sv,val) \
+	do { (sv)->xpadn_low = (val); } while(0)
+#  define COP_SEQ_RANGE_HIGH_set(sv,val) \
+	do { (sv)->xpadn_high = (val); } while(0)
+# elif PERL_VERSION_GE(5,9,5)
 #  define COP_SEQ_RANGE_LOW_set(sv,val) \
 	do { ((XPVNV*)SvANY(sv))->xnv_u.xpad_cop_seq.xlow = val; } while(0)
 #  define COP_SEQ_RANGE_HIGH_set(sv,val) \
@@ -95,6 +100,12 @@ static SV *THX_newSV_type(pTHX_ svtype t
 # define GV_NOTQUAL 0
 #endif /* !GV_NOTQUAL */
 
+#ifndef padnamelist_store
+ /* Note that the return values are different.  If we ever call it in non-
+    void context, we would have to change it to *av_store.  */
+# define padnamelist_store av_store
+#endif
+
 /*
  * scalar classification
  *
@@ -460,13 +471,18 @@ static void THX_setup_pad(pTHX_ CV *comp
 	PADNAMELIST *padname = PadlistNAMES(padlist);
 	PAD *padvar = PadlistARRAY(padlist)[1];
 	PADOFFSET ouroffset;
-	SV *ourname, *ourvar;
+	PADNAME *ourname;
+	SV *ourvar;
 	HV *stash;
 	ourvar = *av_fetch(padvar, PadMAX(padvar) + 1, 1);
 	SvPADMY_on(ourvar);
 	ouroffset = PadMAX(padvar);
+#ifdef newPADNAMEpvn
+	ourname = newPADNAMEpvn(name, strlen(name));
+#else
 	ourname = newSV_type(SVt_PADNAME);
 	sv_setpv(ourname, name);
+#endif
 	SvPAD_OUR_on(ourname);
 	stash = name[0] == '$' ? stash_lex_sv :
 		name[0] == '@' ? stash_lex_av : stash_lex_hv;
@@ -474,7 +490,7 @@ static void THX_setup_pad(pTHX_ CV *comp
 	COP_SEQ_RANGE_LOW_set(ourname, PL_cop_seqmax);
 	COP_SEQ_RANGE_HIGH_set(ourname, pad_max());
 	PL_cop_seqmax++;
-	av_store(padname, ouroffset, ourname);
+	padnamelist_store(padname, ouroffset, ourname);
 #ifdef PadnamelistMAXNAMED
 	PadnamelistMAXNAMED(padname) = ouroffset;
 #endif /* PadnamelistMAXNAMED */
