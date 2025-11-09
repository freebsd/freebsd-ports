--- ui/accessibility/ax_tree.h.orig	2025-08-26 20:49:50 UTC
+++ ui/accessibility/ax_tree.h
@@ -64,7 +64,7 @@ enum class AXTreeUnserializeError {
 };
 // LINT.ThenChange(/tools/metrics/histograms/metadata/accessibility/enums.xml:AccessibilityTreeUnserializeError)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // To support AriaNotify on older versions of ATK, we need to use the ATK
 // signal "Text::text-insert". This signal requires a node that is a
 // text type, and it needs to have aria-live properties set in order for
@@ -289,7 +289,7 @@ class AX_EXPORT AXTree {
 
   void NotifyChildTreeConnectionChanged(AXNode* node, AXTree* child_tree);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   void ClearExtraAnnouncementNodes();
   void CreateExtraAnnouncementNodes();
   ExtraAnnouncementNodes* extra_announcement_nodes() const {
@@ -548,7 +548,7 @@ class AX_EXPORT AXTree {
 
   std::unique_ptr<AXEvent> event_data_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ExtraAnnouncementNodes> extra_announcement_nodes_ = nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 };
