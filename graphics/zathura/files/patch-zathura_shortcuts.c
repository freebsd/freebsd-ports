X-Git-Url: https://git.pwmt.org/?p=zathura.git;a=blobdiff_plain;f=zathura%2Fshortcuts.c;h=93182c0835f3c41157637f7d2b78dbb7ff3b1328;hp=0e6ca6349a529a9faff75f2a445f7cf0b7a3c98c;hb=8d71a755d648c5856ef91d214bfdb46925f6c2f0;hpb=10f3da57c65a8ed7d4d3beff3e49da2bcddcf7a7

diff --git zathura/shortcuts.c zathura/shortcuts.c.orig
index 0e6ca63..93182c0 100644
--- zathura/shortcuts.c
+++ zathura/shortcuts.c.orig
@@ -861,9 +861,11 @@ sc_search(girara_session_t* session, girara_argument_t* argument,
   const unsigned int num_pages = zathura_document_get_number_of_pages(zathura->document);
   const unsigned int cur_page  = zathura_document_get_current_page_number(zathura->document);
   GtkWidget *cur_page_widget = zathura_page_get_widget(zathura, zathura_document_get_page(zathura->document, cur_page));
-  bool nohlsearch, first_time_after_abort, draw;
+  bool nohlsearch, first_time_after_abort;
+  gboolean draw;
 
-  nohlsearch = first_time_after_abort = draw = false;
+  nohlsearch = first_time_after_abort = false;
+  draw = FALSE;
   girara_setting_get(session, "nohlsearch", &nohlsearch);
 
   if (nohlsearch == false) {
