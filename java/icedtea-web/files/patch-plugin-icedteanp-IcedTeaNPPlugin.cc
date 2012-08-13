--- plugin/icedteanp/IcedTeaNPPlugin.cc	Thu Aug 02 09:11:37 2012 -0400
+++ plugin/icedteanp/IcedTeaNPPlugin.cc	Tue Aug 07 10:59:11 2012 -0400
@@ -2053,8 +2053,13 @@
 
   //Ensure any unused fields are NULL
   memset(&browser_functions, 0, sizeof(NPNetscapeFuncs));
+
+  //browserTable->size can be larger than sizeof(NPNetscapeFuncs) (PR1106)
+  size_t copySize = browserTable->size < sizeof(NPNetscapeFuncs) ?
+                    browserTable->size : sizeof(NPNetscapeFuncs);
+
   //Copy fields according to given size
-  memcpy(&browser_functions, browserTable, browserTable->size);
+  memcpy(&browser_functions, browserTable, copySize);
 
   return true;
 }
