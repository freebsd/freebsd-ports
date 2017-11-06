Fix compiling with libc++ and Clang

src/world.cpp:689:53: error: no viable conversion from '__map_iterator<__tree_iterator<__value_type<unsigned int, [...]>, class std::__1::__tree_node<union
      std::__1::__value_type<unsigned int, struct base_item_s *>, void *> *, [...]>>' to '__map_iterator<__tree_iterator<__value_type<const unsigned int, [...]>, class std::__1::__tree_node<union std::__1::__value_type<const unsigned int, struct base_item_s *>, void
      *> *, [...]>>'
    std::map<const uint32_t, base_item_p>::iterator it = global_world.items_tree.find(item_id);
                                                    ^    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
--- src/world.cpp.orig	2017-04-23 13:39:54 UTC
+++ src/world.cpp
@@ -686,7 +686,7 @@ int World_CreateItem(uint32_t item_id, u
 
 int World_DeleteItem(uint32_t item_id)
 {
-    std::map<const uint32_t, base_item_p>::iterator it = global_world.items_tree.find(item_id);
+    std::map<uint32_t, base_item_p>::iterator it = global_world.items_tree.find(item_id);
 
     if(it != global_world.items_tree.end())
     {
