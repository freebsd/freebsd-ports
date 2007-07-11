--- ./src/FinishedList.cpp.orig	Mon Mar 12 01:45:24 2007
+++ ./src/FinishedList.cpp	Sun Jun 24 23:27:13 2007
@@ -203,7 +203,7 @@
             wxDateTime date;
             value = 0;
             config->Read(START_REG,&value);
-            date.Set(value);
+            date.Set((time_t)value);
             infolist->SetItem(5,1,date.Format());
         }
 
@@ -211,7 +211,7 @@
             wxDateTime date;
             value = 0;
             config->Read(END_REG,&value);
-            date.Set(value);
+            date.Set((time_t)value);
             infolist->SetItem(6,1,date.Format());
         }
 
