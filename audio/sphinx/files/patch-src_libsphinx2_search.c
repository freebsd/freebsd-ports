--- src/libsphinx2/search.c.orig	2001-12-13 21:11:24 UTC
+++ src/libsphinx2/search.c
@@ -2236,6 +2236,9 @@ search_one_ply_fwd (void)
     lm_next_frame ();
 }
 
+static void compute_phone_perplexity( void );
+static search_hyp_t *fwdtree_pscr_path ( void );
+
 void
 search_finish_fwd (void)
 {
@@ -2245,7 +2248,6 @@ search_finish_fwd (void)
     CHAN_T *hmm, /* *thmm,*/ **acl;
     /* int32 bp, bestbp, bestscore; */
     /* int32 l_scr; */
-    static void compute_phone_perplexity( void );
     
     if ((CurrentFrame > 0) && (topsen_window > 1)) {
 	/* Wind up remaining frames */
@@ -2306,7 +2308,6 @@ search_finish_fwd (void)
     /* Get pscr-score for fwdtree recognition */
     {
 	search_hyp_t *pscrpath;
-	static search_hyp_t *fwdtree_pscr_path ( void );
 	
 	if (query_phone_conf ()) {
 	    pscrpath = fwdtree_pscr_path ();
