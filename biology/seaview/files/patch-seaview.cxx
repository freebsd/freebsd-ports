--- seaview.cxx.orig	2018-08-25 03:49:10 UTC
+++ seaview.cxx
@@ -3349,7 +3349,7 @@ else if(reponse == PRINTOUT && view->tot_seqs > 0) {
 	if(p != NULL) *p = 0;
 	if(printout_black == TEXT_ONLY) strcat(suggested, ".txt");
 	else {
-		strcat(suggested, "."PDF_OR_PS_EXT);
+		strcat(suggested, "." PDF_OR_PS_EXT);
 		}
 if( view->alt_col_rank != NULL ) {
 		for(anerr = 0; anerr < view->tot_seqs; anerr++)
@@ -3459,7 +3459,7 @@ fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
 
 pdf_form = new Fl_Window(415, 90);
 pdf_form->box(FL_FLAT_BOX);
-pdf_form->label("Set "PDF_OR_PS" output options");
+pdf_form->label("Set " PDF_OR_PS " output options");
 
 x = 5 + (int)fl_width("block size:"); y = 5; w = 50; h = 25;
 sizeinput = new Fl_Input(x, y, w, h, "font size:");
@@ -5048,10 +5048,10 @@ menus->spacing(2);
     {"Save prot alignmt", 0,file_menu_callback, 0, FL_MENU_INACTIVE},
     {"Save bootstrap replicates", 0,file_menu_callback, 0, FL_MENU_INACTIVE | FL_MENU_DIVIDER},
 #if !defined(__APPLE__)
-    {"Prepare "PDF_OR_PS"", 0, file_menu_callback, 0, 0},
-    {""PDF_OR_PS" options...", 0, file_menu_callback, 0, FL_MENU_DIVIDER},
+    {"Prepare " PDF_OR_PS "", 0, file_menu_callback, 0, 0},
+    {"" PDF_OR_PS " options...", 0, file_menu_callback, 0, FL_MENU_DIVIDER},
 #else
-    {"Prepare "PDF_OR_PS"", 0, file_menu_callback, 0, FL_MENU_DIVIDER},
+    {"Prepare " PDF_OR_PS "", 0, file_menu_callback, 0, FL_MENU_DIVIDER},
 #endif
     {"Concatenate", 0,file_menu_callback, 0, FL_MENU_DIVIDER},
     {"New window", FL_COMMAND | 'n', file_menu_callback, 0, 0},
