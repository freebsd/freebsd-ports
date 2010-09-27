--- bse/bsecxxplugin.hh.orig	2010-09-16 07:35:32.000000000 +0000
+++ bse/bsecxxplugin.hh	2010-09-16 07:36:25.000000000 +0000
@@ -55,7 +55,7 @@
 #define BSE_CXX_REGISTER_STATIC_HOOK(HookType)  BSE_CXX_REGISTER_HOOK_NODE (HookType, 1)
 #define BSE_CXX_REGISTER_HOOK_NODE(HookType, __static)                  \
   template<class E> static BseExportNode* bse_export_node ();           \
-  template<> inline BseExportNode*                                      \
+  template<> inline static BseExportNode*                                      \
   bse_export_node<HookType> ()                                          \
   {                                                                     \
     static BseExportNodeHook hnode = {                                  \
@@ -90,7 +90,7 @@
   (::NameSpace::bse_type_keeper__3##EnumType.get_type ())
 #define BSE_CXX_DECLARE_ENUM(EnumType,EnumName,N,ICode)                 \
   template<class E> static BseExportNode* bse_export_node ();           \
-  template<> BseExportNode*                                             \
+  template<> static BseExportNode*                                             \
   bse_export_node<EnumType> ()                                          \
   {                                                                     \
     static BseExportNodeEnum enode = {                                  \
@@ -144,7 +144,7 @@
   (::NameSpace::bse_type_keeper__1##RecordType.get_type ())
 #define BSE_CXX_DECLARE_RECORD(RecordType)                              \
   template<class E> static BseExportNode* bse_export_node ();           \
-  template<> BseExportNode*                                             \
+  template<> static BseExportNode*                                             \
   bse_export_node<RecordType> ()                                        \
   {                                                                     \
     static BseExportNodeBoxed bnode = {                                 \
@@ -180,7 +180,7 @@
   (::NameSpace::bse_type_keeper__2##SequenceType.get_type ())
 #define BSE_CXX_DECLARE_SEQUENCE(SequenceType)                                  \
   template<class E> static BseExportNode* bse_export_node ();                   \
-  template<> BseExportNode*                                                     \
+  template<> static BseExportNode*                                                     \
   bse_export_node<SequenceType> ()                                              \
   {                                                                             \
     static BseExportNodeBoxed bnode = {                                         \
