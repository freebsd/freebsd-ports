--- bear-engine/core/src/engine/script/code/script_runner.cpp.orig	2011-07-17 23:01:25.000000000 +0400
+++ bear-engine/core/src/engine/script/code/script_runner.cpp	2013-09-17 23:44:12.620520919 +0400
@@ -108,7 +108,7 @@
   bool done(false);
 
   while ( !done && (m_current_call != m_sequence.end()) )
-    if ( claw::real_number<universe::time_type>(m_current_call->date) > m_date )
+    if ( claw::real_number<universe::time_type>(m_current_call->date) > claw::real_number<universe::time_type>(m_date) )
       done = true;
     else
       {
