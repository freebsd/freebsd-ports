--- sc/inc/mtvelements.hxx.org	2013-07-25 21:25:20.837766596 +0200
+++ sc/inc/mtvelements.hxx	2013-07-25 21:26:32.853493134 +0200
@@ -63,11 +63,11 @@
 namespace sc {
 
 // Broadcaster storage container
-typedef mdds::mtv::custom_block_func1<sc::element_type_broadcaster, sc::custom_broadcaster_block> BCBlkFunc;
+typedef mdds::mtv::custom_block_func1<sc::custom_broadcaster_block> BCBlkFunc;
 typedef mdds::multi_type_vector<BCBlkFunc> BroadcasterStoreType;
 
 // Cell text attribute container.
-typedef mdds::mtv::custom_block_func1<sc::element_type_celltextattr, sc::custom_celltextattr_block> CTAttrFunc;
+typedef mdds::mtv::custom_block_func1<sc::custom_celltextattr_block> CTAttrFunc;
 typedef mdds::multi_type_vector<CTAttrFunc> CellTextAttrStoreType;
 
 /**
--- sc/source/core/tool/scmatrix.cxx.org	2013-07-25 21:26:36.733621612 +0200
+++ sc/source/core/tool/scmatrix.cxx	2013-07-25 21:27:08.784683394 +0200
@@ -89,7 +89,7 @@
             }
         }
 
-        static void delete_block(mdds::mtv::base_element_block* p)
+        static void delete_block(const mdds::mtv::base_element_block* p)
         {
             if (!p)
                 return;
