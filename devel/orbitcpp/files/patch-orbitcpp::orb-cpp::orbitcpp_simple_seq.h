--- orbitcpp/orb-cpp/orbitcpp_simple_seq.h.orig	Wed Jul 23 10:12:57 2003
+++ orbitcpp/orb-cpp/orbitcpp_simple_seq.h	Wed Jul 23 10:15:59 2003
@@ -35,6 +35,7 @@
     class SimpleSeqBase: public SequenceBase <typename Traits::value_t,
 		typename Traits::c_value_t, typename Traits::c_seq_t>
     {
+    public:
 	typedef Traits                       traits_t;
 	typedef typename Traits::value_t     value_t;
 	typedef typename traits_t::c_value_t c_value_t;
