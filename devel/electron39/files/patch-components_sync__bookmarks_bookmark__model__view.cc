--- components/sync_bookmarks/bookmark_model_view.cc.orig	2025-10-21 20:19:54 UTC
+++ components/sync_bookmarks/bookmark_model_view.cc
@@ -9,7 +9,7 @@
 #include "components/bookmarks/browser/bookmark_model.h"
 #include "components/bookmarks/browser/bookmark_node.h"
 #include "components/bookmarks/common/bookmark_metrics.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/sync_bookmarks/initial_account_bookmark_deduplicator.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -250,7 +250,7 @@ void BookmarkModelViewUsingAccountNodes::
 
 void BookmarkModelViewUsingAccountNodes::
     MaybeRemoveUnderlyingModelDuplicatesUponInitialSync() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   InitialAccountBookmarkDeduplicator initial_account_bookmark_deduplicator(
       underlying_model());
   initial_account_bookmark_deduplicator.Deduplicate();
