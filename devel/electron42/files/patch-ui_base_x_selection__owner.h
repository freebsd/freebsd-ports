--- ui/base/x/selection_owner.h.orig	2026-04-28 21:06:17 UTC
+++ ui/base/x/selection_owner.h
@@ -19,7 +19,7 @@
 #include "ui/gfx/x/connection.h"
 #include "ui/gfx/x/event.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/memory/weak_ptr.h"
 #endif
 
@@ -136,7 +136,7 @@ class COMPONENT_EXPORT(UI_BASE_X) SelectionOwner {
   std::vector<IncrementalTransfer>::iterator FindIncrementalTransferForEvent(
       const x11::PropertyNotifyEvent& event);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnPortalPathsRegistered(x11::SelectionRequestEvent request,
                                std::string key);
 #endif
@@ -160,7 +160,7 @@ class COMPONENT_EXPORT(UI_BASE_X) SelectionOwner {
   // Used to abort stale incremental data transfers.
   base::RepeatingTimer incremental_transfer_abort_timer_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::WeakPtrFactory<SelectionOwner> weak_factory_{this};
 #endif
 };
