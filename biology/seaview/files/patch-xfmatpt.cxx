--- xfmatpt.cxx.orig	2018-08-25 03:50:10 UTC
+++ xfmatpt.cxx
@@ -205,7 +205,7 @@ fin += width + 2;
 compute->callback(compute_proc, fdui);
 fdui->compute_butt = compute;
 
-Fl_Widget *postscript = cre_button(fin, curr_y, &width, but_height, fontsize, "Write "PDF_OR_PS);
+Fl_Widget *postscript = cre_button(fin, curr_y, &width, but_height, fontsize, "Write " PDF_OR_PS);
 fin += width;
 postscript->callback(plot_button_proc, fdui);
 
@@ -870,7 +870,7 @@ if (setjmp(*jbuf) == 0) {
 #ifndef MICRO
   matpt->form->hide(); Fl::flush(); // because of strange bug on 32-bit Linux only
 #endif
-  fl_message("Dot plot is now in file\n%s\nin "PDF_OR_PS" format", surface->outfname());
+  fl_message("Dot plot is now in file\n%s\nin " PDF_OR_PS " format", surface->outfname());
   delete surface;
 #ifndef MICRO
   matpt->form->show(); Fl::flush();
