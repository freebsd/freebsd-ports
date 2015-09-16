--- cpp/test/Ice/hold/AllTests.cpp.orig	2015-06-23 17:30:20.000000000 +0200
+++ cpp/test/Ice/hold/AllTests.cpp	2015-08-02 15:05:08.363617996 +0200
@@ -152,31 +152,46 @@
         ConditionPtr cond = new Condition(true);
         int value = 0;
         Ice::AsyncResultPtr result;
+        cout << __LINE__ << " (" << time(0) << ")" << endl;
         while(value < 3000 && cond->value())
         {
+            if (!value)
+                cout << __LINE__ << " (" << time(0) << ")" << endl;
             result = holdSerialized->begin_set(value + 1,
                                                IceUtilInternal::random(1),
                                                newCallback_Hold_set(new SetCB(cond, value), 
                                                                     &SetCB::response, 
                                                                     &SetCB::exception));
+            if (!value)
+                cout << __LINE__ << " (" << time(0) << ")" << endl;
             ++value;
             if(value % 100 == 0)
             {
+                cout << __LINE__ << " (" << time(0) << ")" << endl;
                 result->waitForSent();
             }
         }
+        cout << __LINE__ << " (" << time(0) << ")" << endl;
         result->waitForCompleted();
+        cout << __LINE__ << " (" << time(0) << ")" << endl;
         test(cond->value());
+        cout << __LINE__ << " (" << time(0) << ")" << endl;
 
         for(int i = 0; i < 10000; ++i)
         {
+            if (value == 3000)
+                cout << __LINE__ << " (" << time(0) << ")" << endl;
             holdSerialized->ice_oneway()->setOneway(value + 1, value);
+            if (value == 3000)
+                cout << __LINE__ << " (" << time(0) << ")" << endl;
             ++value;
             if((i % 100) == 0)
             {
+                cout << __LINE__ << " (" << time(0) << ")" << endl;
                 holdSerialized->ice_oneway()->putOnHold(1);
             }
         }
+        cout << __LINE__ << " (" << time(0) << ")" << endl;
     }
     cout << "ok" << endl;
 
