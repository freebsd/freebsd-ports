# Origin: https://github.com/naev/naev/commit/6f4005f921650c1a8930721bbd1c0eab163673f8
# Subject: * Hook param off by one.
# https://github.com/naev/naev/commit/3ba9cafb369f94115c897717b6f38415348f4c8f
# Subject: * Too many bugs in the code, should fix bugs with pilot hooks when using >1 parameter.

--- src/pilot_hook.c.orig	2015-02-16 17:49:03 UTC
+++ src/pilot_hook.c
@@ -39,26 +39,26 @@ static int pilot_hookCleanup = 0; /**< A
 int pilot_runHookParam( Pilot* p, int hook_type, HookParam* param, int nparam )
 {
    int n, i, run, ret;
-   HookParam hparam[3], *hdynparam;
+   HookParam hstaparam[5], *hdynparam, *hparam;
 
    /* Set up hook parameters. */
-   if (nparam <= 1) {
-      hparam[0].type       = HOOK_PARAM_PILOT;
-      hparam[0].u.lp.pilot = p->id;
+   if (nparam <= 3) {
+      hstaparam[0].type       = HOOK_PARAM_PILOT;
+      hstaparam[0].u.lp.pilot = p->id;
       n  = 1;
-      if (nparam == 1) {
-         memcpy( &hparam[n], param, sizeof(HookParam) );
-         n++;
-      }
-      hparam[n].type    = HOOK_PARAM_SENTINEL;
+      memcpy( &hstaparam[n], param, sizeof(HookParam)*nparam );
+      n += nparam;
+      hstaparam[n].type = HOOK_PARAM_SENTINEL;
       hdynparam         = NULL;
+      hparam            = hstaparam;
    }
    else {
       hdynparam   = malloc( sizeof(HookParam) * (nparam+2) );
       hdynparam[0].type       = HOOK_PARAM_PILOT;
       hdynparam[0].u.lp.pilot = p->id;
       memcpy( &hdynparam[1], param, sizeof(HookParam)*nparam );
-      hdynparam[nparam].type  = HOOK_PARAM_SENTINEL;
+      hdynparam[nparam+1].type  = HOOK_PARAM_SENTINEL;
+      hparam                  = hdynparam;
    }
 
    /* Run pilot specific hooks. */
