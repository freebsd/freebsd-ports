- fix build with clang-19, see https://github.com/simongog/sdsl-lite/issues/462

--- include/sdsl/louds_tree.hpp.orig	2024-11-03 05:50:59 UTC
+++ include/sdsl/louds_tree.hpp
@@ -176,12 +176,13 @@ class louds_tree
             return v.nr;
         }
 
-
+#if 0
         void swap(louds_tree& tree) {
             m_bv.swap(tree.m_bv);
             util::swap_support(m_bv_select1, tree.m_select1, &m_bv, &(tree.m_bv));
             util::swap_support(m_bv_select0, tree.m_select0, &m_bv, &(tree.m_bv));
         }
+#endif
 
         size_type serialize(std::ostream& out, structure_tree_node* v=nullptr, std::string name="")const {
             structure_tree_node* child = structure_tree::add_child(v, name, util::class_name(*this));
