--- src/recur.cpp.orig	2015-10-21 20:50:42 UTC
+++ src/recur.cpp
@@ -241,7 +241,7 @@ ISO8601d getNextRecurrence (ISO8601d& cu
     else if (dow == 6) days = 2;
     else               days = 1;
 
-    return current + (days * 86400);
+    return current + (time_t)(days * 86400);
   }
 
   else if (Lexer::isDigit (period[0]) &&
@@ -377,7 +377,7 @@ ISO8601d getNextRecurrence (ISO8601d& cu
     throw std::string (format (STRING_TASK_VALID_RECUR, period));
 
   secs = (time_t) p;
-  return current + secs;
+  return current + (time_t) secs;
 }
 
 ////////////////////////////////////////////////////////////////////////////////
