--- orbitcpp/orb-cpp/orbitcpp_compound_seq.h.orig	Mon Aug 25 15:16:07 2003
+++ orbitcpp/orb-cpp/orbitcpp_compound_seq.h	Mon Aug 25 15:16:55 2003
@@ -70,6 +70,7 @@
 	typename SeqTraits::c_value_t,
         typename SeqTraits::c_seq_t>
     {
+    protected:
 	typedef SeqTraits  traits_t;
 	typedef typename traits_t::value_t   value_t;
 	typedef typename traits_t::c_value_t c_value_t;
@@ -126,6 +127,7 @@
     template<typename CPPElem, typename SeqTraits=typename CPPElem::SeqTraits>
     class CompoundUnboundedSeq: public CompoundSeqBase<CPPElem, SeqTraits>
     {
+    public:
 	typedef SeqTraits  traits_t;
 	typedef typename traits_t::c_value_t c_value_t;
 	typedef typename traits_t::c_seq_t   c_seq_t;
@@ -186,6 +188,7 @@
     template<typename CPPElem, CORBA::ULong max, typename SeqTraits=typename CPPElem::SeqTraits>
     class CompoundBoundedSeq: public CompoundSeqBase<CPPElem, SeqTraits>
     {
+    public:
 	typedef SeqTraits traits_t;
 	typedef typename traits_t::value_t  value_t;
 	typedef typename traits_t::c_value_t c_value_t;
