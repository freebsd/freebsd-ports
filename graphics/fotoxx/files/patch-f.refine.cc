--- f.refine.cc.orig	2022-01-01 11:16:58 UTC
+++ f.refine.cc
@@ -223,7 +223,7 @@ void m_edit_dist(GtkWidget *, cchar *menu)
    EFedit_dist.Farea = 2;                                                        //  select area usable
    EFedit_dist.Frestart = 1;                                                     //  restart allowed
    EFedit_dist.Fscript = 1;                                                      //  scripting supported 
-   EFedit_dist.threadfunc = thread;
+   EFedit_dist.threadfunc = edit_dist_names::thread;
    if (! edit_setup(EFedit_dist)) return;                                        //  setup edit
 
 /***
@@ -589,7 +589,7 @@ void m_flatten_dist(GtkWidget *, cchar *menu)
    EFflatten_dist.Frestart = 1;                                                  //  restartable
    EFflatten_dist.Fpaintedits = 1;                                               //  use with paint edits OK
    EFflatten_dist.Fscript = 1;                                                   //  scripting supported
-   EFflatten_dist.threadfunc = thread;
+   EFflatten_dist.threadfunc = flatten_dist_names::thread;
    if (! edit_setup(EFflatten_dist)) return;                                     //  setup edit
 
    Eww = E0pxm->ww;
@@ -1066,7 +1066,7 @@ void flatten_dist_func(int _NZ, int _flatten, int _deb
    EFflatten_dist.menufunc = m_flatten_dist;
    EFflatten_dist.Farea = 2;                                                     //  select area usable
    EFflatten_dist.Frestart = 1;                                                  //  restartable
-   EFflatten_dist.threadfunc = thread;
+   EFflatten_dist.threadfunc = flatten_dist_names::thread;
 
    if (! edit_setup(EFflatten_dist)) return;                                     //  setup edit
 
