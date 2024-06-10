--- f.refine.cc.orig	2023-03-01 07:32:06 UTC
+++ f.refine.cc
@@ -223,7 +223,7 @@ void m_edit_dist(GtkWidget *, ch  *menu)
    EFedit_dist.Farea = 2;                                                        //  select area usable
    EFedit_dist.Fpaintedits = 1;                                                  //  use with paint edits OK               23.50
    EFedit_dist.Fscript = 1;                                                      //  scripting supported 
-   EFedit_dist.threadfunc = thread;
+   EFedit_dist.threadfunc = edit_dist_names::thread;
 
    if (! edit_setup(EFedit_dist)) return;                                        //  setup edit
 
@@ -589,7 +589,7 @@ void m_flatdist(GtkWidget *, ch  *menu)
    EFflatdist.Farea = 2;                                                         //  select area usable
    EFflatdist.Fpaintedits = 1;                                                   //  use with paint edits OK
    EFflatdist.Fscript = 1;                                                       //  scripting supported
-   EFflatdist.threadfunc = thread;
+   EFflatdist.threadfunc = flatdist_names::thread;
 
    if (! edit_setup(EFflatdist)) return;                                         //  setup edit
 
@@ -1067,7 +1067,7 @@ void flatdist_func(int _radius, int _flatten, int _deb
    EFflatdist.menufunc = m_flatdist;
    EFflatdist.Farea = 2;                                                         //  select area usable
    EFflatdist.Fscript = 1;                                                       //  scripting supported                   23.4
-   EFflatdist.threadfunc = thread;
+   EFflatdist.threadfunc = flatdist_names::thread;
 
    if (! edit_setup(EFflatdist)) return;                                         //  setup edit
 
