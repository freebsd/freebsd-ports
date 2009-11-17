--- cgi/accept.cc.orig	2009-09-01 10:41:09.000000000 +0200
+++ cgi/accept.cc	2009-10-05 02:52:05.000000000 +0200
@@ -4,7 +4,7 @@
 {
     for_each(d_buffer.rbegin() + 1, d_buffer.rend(), 
             d_stack, 
-        static_cast<void (stack<char>::*)(char &&)>(&stack<char>::push));
+        static_cast<void (stack<char>::*)(char const &)>(&stack<char>::push));
 
 // With g++4-4 (?)
 //        static_cast<void (stack<char>::*)(char const &)>(&stack<char>::push));
