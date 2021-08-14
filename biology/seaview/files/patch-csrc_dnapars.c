--- csrc/dnapars.c.orig	2019-11-29 14:00:33 UTC
+++ csrc/dnapars.c
@@ -77,41 +77,44 @@ void   load_tree(long treei);
 /* function prototypes */
 
 
-Char infilename[FNMLNGTH], outfilename[FNMLNGTH], intreename[FNMLNGTH], *outtreename,
+extern Char infilename[FNMLNGTH], outfilename[FNMLNGTH], intreename[FNMLNGTH], *outtreename,
      weightfilename[FNMLNGTH];
 char basechar[32]="ACMGRSVTWYHKDBNO???????????????";
-node *root;
-long chars, col, msets, ith, njumble, jumb, maxtrees;
+extern node *root;
+extern long chars, col, msets, ith, njumble, jumb;
+long maxtrees;
 /*   chars = number of sites in actual sequences */
-long inseed, inseed0;
-double threshold;
-boolean jumble, usertree, thresh, weights, thorough, rearrfirst,
-          trout, progress, stepbox, ancseq, mulsets, justwts, firstset, mulf,
-          multf;
+extern long inseed, inseed0;
+extern double threshold;
+extern boolean jumble, usertree, thresh, weights,
+          trout, progress, stepbox, ancseq, mulsets, justwts, firstset;
+boolean thorough, rearrfirst, mulf, multf;
 steptr oldweight;
-longer seed;
-pointarray treenode;            /* pointers to all nodes in tree */
-long *enterorder;
+extern longer seed;
+extern pointarray treenode;            /* pointers to all nodes in tree */
+extern long *enterorder;
 long *zeros;
 
 /* local variables for Pascal maketree, propagated globally for C version: */
 
-long minwhich;
+extern long minwhich;
 static double like, minsteps, bestyet, bestlike, bstlike2;
-boolean lastrearr, recompute;
-double nsteps[maxuser];
-long **fsteps;
-node *there, *oldnufork;
-long *place;
-bestelm *bestrees;
-long *threshwt;
+extern boolean lastrearr, recompute;
+extern double nsteps[maxuser];
+extern long **fsteps;
+extern node *there;
+node *oldnufork;
+extern long *place;
+extern bestelm *bestrees;
+extern long *threshwt;
 baseptr nothing;
-gbases *garbage;
-node *temp, *temp1, *temp2, *tempsum, *temprm, *tempadd, *tempf, *tmp, *tmp1,
+extern gbases *garbage;
+extern node *temp, *temp1;
+node *temp2, *tempsum, *temprm, *tempadd, *tempf, *tmp, *tmp1,
        *tmp2, *tmp3, *tmprm, *tmpadd;
-boolean *names;
+extern boolean *names;
 node *grbg;
-char *progname;
+extern char *progname;
 
 
 static void getoptions(int arg_maxtrees, dnapars_S_option s_option)
