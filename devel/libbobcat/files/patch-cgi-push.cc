--- cgi/push.cc.orig	2009-09-01 10:41:09.000000000 +0200
+++ cgi/push.cc	2009-10-05 02:47:46.000000000 +0200
@@ -3,7 +3,7 @@
 void CGIFSA::push()
 {
     for_each(d_buffer.begin(), d_buffer.end(), d_stack, 
-        static_cast<void (stack<char>::*)(char &&)>(&stack<char>::push));
+        static_cast<void (stack<char>::*)(char const &)>(&stack<char>::push));
 
 // With g++4-4 (?)
 //        static_cast<void (stack<char>::*)(char const &)>(&stack<char>::push));
