--- ui/accessibility/ax_node.h.orig	2025-04-22 20:15:27 UTC
+++ ui/accessibility/ax_node.h
@@ -587,7 +587,7 @@ class AX_EXPORT AXNode final {
   const std::vector<raw_ptr<AXNode, VectorExperimental>>* GetExtraMacNodes()
       const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   AXNode* GetExtraAnnouncementNode(
       ax::mojom::AriaNotificationPriority priority_property) const;
 #endif  // BUILDFLAG(IS_LINUX)
