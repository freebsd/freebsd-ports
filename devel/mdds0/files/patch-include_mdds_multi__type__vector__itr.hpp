--- include/mdds/multi_type_vector_itr.hpp.orig	2015-06-11 23:53:55 UTC
+++ include/mdds/multi_type_vector_itr.hpp
@@ -139,14 +139,15 @@ protected:
     typedef typename parent_type::size_type size_type;
     typedef iterator_value_node<size_type, typename parent_type::element_block_type> node;
 
-    iterator_common_base() : m_cur_node(0, 0) {}
+    iterator_common_base() : m_cur_node(0, 0), m_singular(true) {}
 
     iterator_common_base(
         const base_iterator_type& pos, const base_iterator_type& end,
         size_type start_pos, size_type block_index) :
         m_cur_node(start_pos, block_index),
         m_pos(pos),
-        m_end(end)
+        m_end(end),
+        m_singular(false)
     {
         if (m_pos != m_end)
             update_node();
@@ -154,9 +155,13 @@ protected:
 
     iterator_common_base(const iterator_common_base& other) :
         m_cur_node(other.m_cur_node),
-        m_pos(other.m_pos),
-        m_end(other.m_end)
+        m_singular(other.m_singular)
     {
+        if (!m_singular)
+        {
+            m_pos = other.m_pos;
+            m_end = other.m_end;
+        }
     }
 
     void update_node()
@@ -196,6 +201,7 @@ protected:
     node m_cur_node;
     base_iterator_type m_pos;
     base_iterator_type m_end;
+    bool m_singular;
 
 public:
     bool operator== (const iterator_common_base& other) const
@@ -218,16 +224,34 @@ public:
     iterator_common_base& operator= (const iterator_common_base& other)
     {
         m_cur_node = other.m_cur_node;
-        m_pos = other.m_pos;
-        m_end = other.m_end;
+        m_singular = other.m_singular;
+        if (!m_singular)
+        {
+            m_pos = other.m_pos;
+            m_end = other.m_end;
+        }
         return *this;
     }
 
     void swap(iterator_common_base& other)
     {
         m_cur_node.swap(other.m_cur_node);
-        std::swap(m_pos, other.m_pos);
-        std::swap(m_end, other.m_end);
+        std::swap(m_singular, other.m_singular);
+        if (!(m_singular || other.m_singular))
+        {
+            std::swap(m_pos, other.m_pos);
+            std::swap(m_end, other.m_end);
+        }
+        else if (!m_singular)
+        {
+            m_pos = other.m_pos;
+            m_end = other.m_end;
+        }
+        else if (!other.m_singular)
+        {
+            other.m_pos = m_pos;
+            other.m_end = m_end;
+        }
     }
 
     const node& get_node() const { return m_cur_node; }
