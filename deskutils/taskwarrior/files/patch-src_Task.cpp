--- src/Task.cpp.orig	2015-10-21 20:50:42 UTC
+++ src/Task.cpp
@@ -359,7 +359,7 @@ Task::dateState Task::getDateState (cons
     if (imminentperiod == 0)
       return dateAfterToday;
 
-    ISO8601d imminentDay = today + imminentperiod * 86400;
+    ISO8601d imminentDay = today + imminentperiod * (time_t) 86400;
     if (reference < imminentDay)
       return dateAfterToday;
   }
