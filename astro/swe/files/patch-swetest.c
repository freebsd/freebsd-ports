--- swetest.c.orig	2026-04-16 07:49:51 UTC
+++ swetest.c
@@ -792,6 +792,7 @@ static char smod[2000];
 static char *astro_models;
 static int do_set_astro_models = FALSE;
 static char smod[2000];
+static char spmoon[AS_MAXCH];
 static AS_BOOL inut = FALSE; /* for Astrodienst internal feature */
 static AS_BOOL have_gap_parameter = FALSE; 
 static AS_BOOL use_swe_fixstar2 = FALSE; 
