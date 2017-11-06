--- tads3/vmtz.cpp.orig	2012-08-31 05:09:31 UTC
+++ tads3/vmtz.cpp
@@ -1982,7 +1982,7 @@ void CVmTimeZone::query(vmtzquery *resul
              *   the transition in terms of the local time that was in effect
              *   up until that moment
              */
-            result->set(tcur > 0 ? tcur - 1 : tcur);
+            result->set(cur > 0 ? tcur - 1 : tcur);
             return;
         }
     }
