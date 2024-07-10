--- f.refine.cc.orig	2024-07-01 07:25:41 UTC
+++ f.refine.cc
@@ -257,7 +257,7 @@ void m_edit_dist(GtkWidget *, ch  *menu)
    EFedit_dist.Farea = 2;                                                        //  select area usable
    EFedit_dist.Fpaintedits = 1;                                                  //  use with paint edits OK
    EFedit_dist.Fscript = 1;                                                      //  scripting supported 
-   EFedit_dist.threadfunc = thread;
+   EFedit_dist.threadfunc = edit_dist_names::thread;
 
    if (! edit_setup(EFedit_dist)) return;                                        //  setup edit
 
@@ -653,7 +653,7 @@ void m_flat_dist(GtkWidget *, ch  *menu)
    EFflatdist.Farea = 2;                                                         //  select area usable
    EFflatdist.Fpaintedits = 1;                                                   //  use with paint edits OK
    EFflatdist.Fscript = 1;                                                       //  scripting supported
-   EFflatdist.threadfunc = thread;
+   EFflatdist.threadfunc = flatdist_names::thread;
 
    if (! edit_setup(EFflatdist)) return;                                         //  setup edit
 
@@ -1213,7 +1213,7 @@ void flatdist_func(int _radius, int zones[5])
    EFflatdist.FprevReq = 0;
    EFflatdist.Farea = 2;                                                         //  select area usable
    EFflatdist.Fscript = 1;                                                       //  scripting supported
-   EFflatdist.threadfunc = thread;
+   EFflatdist.threadfunc = flatdist_names::thread;
 
    if (! edit_setup(EFflatdist)) return;                                         //  setup edit
 
