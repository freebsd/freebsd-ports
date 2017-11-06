--- tads3/vmtz.cpp.orig	2013-05-17 19:46:51 UTC
+++ tads3/vmtz.cpp
@@ -1984,7 +1984,7 @@ void CVmTimeZone::query(vmtzquery *resul
              *   the transition in terms of the local time that was in effect
              *   up until that moment
              */
-            result->set(tcur > 0 ? tcur - 1 : tcur);
+            result->set(cur > 0 ? tcur - 1 : tcur);
             return;
         }
     }
