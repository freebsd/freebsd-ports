--- ui/accessibility/ax_tree.cc.orig	2025-06-30 07:04:30 UTC
+++ ui/accessibility/ax_tree.cc
@@ -867,7 +867,7 @@ bool AXTree::ComputeNodeIsIgnoredChanged(
   return old_node_is_ignored != new_node_is_ignored;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 ExtraAnnouncementNodes::ExtraAnnouncementNodes(AXNode* root) {
   assertive_node_ = CreateNode("assertive", root);
   polite_node_ = CreateNode("polite", root);
@@ -960,7 +960,7 @@ void AXTree::Destroy() {
 
 void AXTree::Destroy() {
   base::ElapsedThreadTimer timer;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ClearExtraAnnouncementNodes();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -2181,7 +2181,7 @@ void AXTree::NotifyNodeAttributesWillChange(
                     new_data);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AXTree::ClearExtraAnnouncementNodes() {
   if (!extra_announcement_nodes_) {
     return;
@@ -2570,7 +2570,7 @@ bool AXTree::CreateNewChildVector(
     AXTreeUpdateState* update_state) {
   DCHECK(GetTreeUpdateInProgressState());
   bool success = true;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If the root node has children added, clear the extra announcement nodes,
   // which should always have their indices as the last two children of the root
   // node. They will be recreated if needed, and given the correct indices.
