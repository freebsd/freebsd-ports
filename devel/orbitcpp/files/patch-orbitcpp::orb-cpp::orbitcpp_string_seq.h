--- orbitcpp/orb-cpp/orbitcpp_string_seq.h.orig	Mon Aug 25 15:18:19 2003
+++ orbitcpp/orb-cpp/orbitcpp_string_seq.h	Mon Aug 25 15:45:43 2003
@@ -90,8 +90,10 @@
 
     class StringUnboundedSeq: public StringSeqBase
     {
+    public:
 	typedef StringSeqBase            Super;
 	
+	typedef Super::value_t  value_t;
 	typedef Super::size_t   size_t;
 	typedef Super::index_t  index_t;
 	typedef Super::buffer_t buffer_t;
@@ -145,8 +147,10 @@
     template<CORBA::ULong max>
     class StringBoundedSeq: public StringSeqBase
     {
+    public:
 	typedef StringSeqBase   Super;
 
+	typedef Super::value_t  value_t;
 	typedef Super::size_t   size_t;
 	typedef Super::index_t  index_t;
 	typedef Super::buffer_t buffer_t;
