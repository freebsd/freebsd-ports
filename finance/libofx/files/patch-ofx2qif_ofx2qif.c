--- ofx2qif/ofx2qif.c.orig	Sat Feb 12 16:38:24 2005
+++ ofx2qif/ofx2qif.c	Sat Feb 12 16:38:45 2005
@@ -207,6 +207,7 @@
 extern int ofx_ERROR_msg;
 extern int ofx_INFO_msg;
 extern int ofx_STATUS_msg;
+LibofxContextPtr libofx_context;
  ofx_PARSER_msg = false;
  ofx_DEBUG_msg = false;
  ofx_WARNING_msg = false;
@@ -214,7 +215,7 @@
  ofx_INFO_msg = false;
  ofx_STATUS_msg = false;
 
- LibofxContextPtr libofx_context = libofx_get_new_context();
+ libofx_context = libofx_get_new_context();
  ofx_set_statement_cb(libofx_context, ofx_proc_statement_cb, 0);
  ofx_set_account_cb(libofx_context, ofx_proc_account_cb, 0);
  ofx_set_transaction_cb(libofx_context, ofx_proc_transaction_cb, 0);
