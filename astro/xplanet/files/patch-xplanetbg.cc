--- xplanetbg.cc.orig	Fri Mar 22 04:17:05 2002
+++ xplanetbg.cc	Sun Nov 17 18:26:59 2002
@@ -907,7 +907,7 @@
         
         if (debug)
         {
-            cout << "Finished at " << ctime(&current_time.tv_sec);
+            cout << "Finished at " << ctime((time_t *)&current_time.tv_sec);
             cout << "Sleeping for " << sleep_time << " seconds until "
                  << ctime((time_t *) &next_update) << endl;
         }
