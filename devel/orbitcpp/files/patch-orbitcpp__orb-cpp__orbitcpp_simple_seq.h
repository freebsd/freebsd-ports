--- ./orbitcpp/orb-cpp/orbitcpp_simple_seq.h.orig	2012-07-02 23:33:54.000000000 +0200
+++ ./orbitcpp/orb-cpp/orbitcpp_simple_seq.h	2012-07-02 23:34:43.000000000 +0200
@@ -70,7 +70,7 @@
 	void _length_set_impl (size_t new_length) {
 	    if (new_length > this->_max)
 	    {
-		buffer_t buffer_tmp = allocbuf (new_length);
+		buffer_t buffer_tmp = this->allocbuf (new_length);
 		if (!buffer_tmp)
 		    throw CORBA::NO_MEMORY ();
 		
@@ -78,7 +78,7 @@
 		    buffer_tmp[i] = this->_buffer[i];
 		
 		if (this->_release)
-		    freebuf (this->_buffer);
+		    this->freebuf (this->_buffer);
 		
 		this->_release = true;
 		this->_buffer = buffer_tmp;
