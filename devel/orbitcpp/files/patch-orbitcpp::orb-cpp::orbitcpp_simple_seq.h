--- orbitcpp/orb-cpp/orbitcpp_simple_seq.h.orig	Mon Aug 25 15:17:13 2003
+++ orbitcpp/orb-cpp/orbitcpp_simple_seq.h	Mon Aug 25 15:45:11 2003
@@ -92,8 +92,10 @@
     template<class Traits>
     class SimpleUnboundedSeq: public SimpleSeqBase<Traits>
     {
+    public:
 	typedef SimpleSeqBase<Traits>    Super;
 	
+	typedef typename Super::value_t  value_t;
 	typedef typename Super::size_t   size_t;
 	typedef typename Super::index_t  index_t;
 	typedef typename Super::buffer_t buffer_t;
@@ -146,8 +148,10 @@
     template<class Traits, CORBA::ULong max>
     class SimpleBoundedSeq: public SimpleSeqBase<Traits>
     {
+    public:
 	typedef SimpleSeqBase<Traits>    Super;
 
+	typedef typename Super::value_t  value_t;
 	typedef typename Super::size_t   size_t;
 	typedef typename Super::index_t  index_t;
 	typedef typename Super::buffer_t buffer_t;
