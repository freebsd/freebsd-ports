--- f.enhance.cc.orig	2021-10-17 20:02:26 UTC
+++ f.enhance.cc
@@ -224,7 +224,7 @@ void m_editBD(GtkWidget *, cchar *menu)
    EFeditBD.Farea = 2;                                                           //  select area usable
    EFeditBD.Frestart = 1;                                                        //  restart allowed
    EFeditBD.Fscript = 1;                                                         //  scripting supported 
-   EFeditBD.threadfunc = thread;
+   EFeditBD.threadfunc = editBD_names::thread;
    if (! edit_setup(EFeditBD)) return;                                           //  setup edit
 
 /***
@@ -590,7 +590,7 @@ void m_flattenBD(GtkWidget *, cchar *menu)
    EFflattenBD.Frestart = 1;                                                     //  restartable
    EFflattenBD.Fpaintedits = 1;                                                  //  use with paint edits OK
    EFflattenBD.Fscript = 1;                                                      //  scripting supported
-   EFflattenBD.threadfunc = thread;
+   EFflattenBD.threadfunc = flattenBD_names::thread;
    if (! edit_setup(EFflattenBD)) return;                                        //  setup edit
 
    Eww = E0pxm->ww;
@@ -1067,7 +1067,7 @@ void flattenBDfunc(int _NZ, int _flatten, int _deband1
    EFflattenBD.menufunc = m_flattenBD;
    EFflattenBD.Farea = 2;                                                        //  select area usable
    EFflattenBD.Frestart = 1;                                                     //  restartable
-   EFflattenBD.threadfunc = thread;
+   EFflattenBD.threadfunc = flattenBD_names::thread;
 
    if (! edit_setup(EFflattenBD)) return;                                        //  setup edit
 
