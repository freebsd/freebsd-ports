--- orbitcpp/orb-cpp/orbitcpp_simple_seq.h.orig	Fri May 30 02:10:38 2003
+++ orbitcpp/orb-cpp/orbitcpp_simple_seq.h	Wed Jul 23 10:56:55 2003
@@ -35,6 +35,7 @@
     class SimpleSeqBase: public SequenceBase <typename Traits::value_t,
 		typename Traits::c_value_t, typename Traits::c_seq_t>
     {
+    public:
 	typedef Traits                       traits_t;
 	typedef typename Traits::value_t     value_t;
 	typedef typename traits_t::c_value_t c_value_t;
@@ -91,6 +92,7 @@
     template<class Traits>
     class SimpleUnboundedSeq: public SimpleSeqBase<Traits>
     {
+    public:
 	typedef SimpleSeqBase<Traits>    Super;
 	
 	typedef typename Super::size_t   size_t;
@@ -145,6 +147,7 @@
     template<class Traits, CORBA::ULong max>
     class SimpleBoundedSeq: public SimpleSeqBase<Traits>
     {
+    public:
 	typedef SimpleSeqBase<Traits>    Super;
 
 	typedef typename Super::size_t   size_t;
