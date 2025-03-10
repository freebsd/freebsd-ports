--- f.refine.cc.orig	2024-10-01 05:03:10 UTC
+++ f.refine.cc
@@ -76,7 +76,7 @@ void m_edit_hist(GtkWidget *, ch  *menu)
    EFedit_hist.Farea = 2;                                                        //  select area usable
    EFedit_hist.Fpaintedits = 1;                                                  //  use with paint edits OK
    EFedit_hist.Fscript = 1;                                                      //  scripting supported 
-   EFedit_hist.threadfunc = thread;
+   EFedit_hist.threadfunc = edit_hist_names::thread;
 
    if (! edit_setup(EFedit_hist)) return;                                        //  setup edit
 
