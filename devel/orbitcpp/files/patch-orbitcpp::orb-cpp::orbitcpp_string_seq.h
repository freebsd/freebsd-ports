--- orbitcpp/orb-cpp/orbitcpp_string_seq.h.orig	Wed Jul 23 10:57:57 2003
+++ orbitcpp/orb-cpp/orbitcpp_string_seq.h	Wed Jul 23 10:58:52 2003
@@ -35,7 +35,7 @@
     class StringSeqBase: public SequenceBase <CORBA::String_mgr,
 			 CORBA_char*, CORBA_sequence_CORBA_string>
     {
-    protected:
+    public:
 	typedef CORBA::String_mgr           value_t;
 	typedef CORBA_char*                 c_value_t;
 	typedef CORBA_sequence_CORBA_string c_seq_t;
@@ -90,6 +90,7 @@
 
     class StringUnboundedSeq: public StringSeqBase
     {
+    public:
 	typedef StringSeqBase            Super;
 	
 	typedef Super::size_t   size_t;
@@ -145,6 +146,7 @@
     template<CORBA::ULong max>
     class StringBoundedSeq: public StringSeqBase
     {
+    public:
 	typedef StringSeqBase   Super;
 
 	typedef Super::size_t   size_t;
