--- gnucash/import-export/import-main-matcher.cpp.orig	2024-03-29 20:42:22 UTC
+++ gnucash/import-export/import-main-matcher.cpp
@@ -847,7 +847,7 @@ gnc_gen_trans_assign_transfer_account_to_selection_cb 
     bool is_selection = true;
     auto debugging_enabled{qof_log_check (G_LOG_DOMAIN, QOF_LOG_DEBUG)};
 
-    DEBUG("Rows in selection = %ld", selected_refs.size());
+    DEBUG("Rows in selection = %zu", selected_refs.size());
 
     for (const auto& ref : selected_refs)
     {
