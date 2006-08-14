--- tests/charinbuffer_test.cpp.orig	Sat Aug 12 23:02:38 2006
+++ tests/charinbuffer_test.cpp	Sat Aug 12 23:03:00 2006
@@ -596,7 +596,7 @@
 	IPv4Socket& s = *this;
 		
 	if (state () == Task2::start) {
-		Assure_exit (s.write (&REQUEST [m_idx], 1) == 1);
+		Assure_exit (s.write (&((REQUEST.c_str())[m_idx]), 1) == 1);
 		s << flush;
 		DL((APP,"<== Sent \"%c\" to Loopback\n", REQUEST [m_idx] ));
 
