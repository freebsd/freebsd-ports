--- src/FinishedList.cpp.orig	2007-03-11 22:45:24 UTC
+++ src/FinishedList.cpp
@@ -203,7 +203,7 @@ void mFinishedList::SelectUnselect(bool 
             wxDateTime date;
             value = 0;
             config->Read(START_REG,&value);
-            date.Set(value);
+            date.Set((time_t)value);
             infolist->SetItem(5,1,date.Format());
         }
 
@@ -211,7 +211,7 @@ void mFinishedList::SelectUnselect(bool 
             wxDateTime date;
             value = 0;
             config->Read(END_REG,&value);
-            date.Set(value);
+            date.Set((time_t)value);
             infolist->SetItem(6,1,date.Format());
         }
 
