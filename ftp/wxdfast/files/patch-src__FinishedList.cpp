--- ./src/FinishedList.cpp.orig	Sun Oct 29 12:08:39 2006
+++ ./src/FinishedList.cpp	Tue Nov  7 19:55:03 2006
@@ -186,7 +186,7 @@
             wxDateTime date;
             value = 0;
             config->Read(START_REG,&value);
-            date.Set(value);
+            date.Set((time_t)value);
             infolist->SetItem(5,1,date.Format());
         }
 
@@ -194,7 +194,7 @@
             wxDateTime date;
             value = 0;
             config->Read(END_REG,&value);
-            date.Set(value);
+            date.Set((time_t)value);
             infolist->SetItem(6,1,date.Format());
         }
 
