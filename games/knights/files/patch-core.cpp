--- knights/core.cpp.orig	Sat Aug 21 10:14:24 2004
+++ knights/core.cpp	Sat Aug 21 10:28:14 2004
@@ -90,7 +90,7 @@
         else
         {
           /* Use an existing internetIO */
-          (io_base*)internetioPtr = myIOMap.find(Null);
+          internetioPtr = (io_internet*)myIOMap.find(Null);
           if( internetioPtr == NULL )
           {
             kdWarning() << "core::createNewIO: Trying to connect a match to an internetIO that doesn't exsist." << endl;
@@ -114,12 +114,12 @@
         }
         else
         {
-          (io_base*)internetioPtr = myIOMap.find(ID);
+          internetioPtr = (io_internet*)myIOMap.find(ID);
           if( internetioPtr == NULL )
           {
             /* no io mapped to the ID yet, use the internetio */
             /* Use an existing internetIO */
-            (io_base*)internetioPtr = myIOMap.find(Null);
+            internetioPtr = (io_internet*)myIOMap.find(Null);
             if( internetioPtr == NULL )
             {
               kdWarning() << "core::createNewIO: Trying to connect a match to an internetIO that doesn't exsist." << endl;
