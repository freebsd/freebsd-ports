--- lib/dialogs.h.old	Tue Jun 19 18:29:26 2001
+++ lib/dialogs.h	Tue Jun 19 18:29:41 2001
@@ -407,7 +407,7 @@
 
     TSItem( const char *aValue, TSItem *aNext )
         { value = newStr(aValue); next = aNext; }
-    ~TSItem() { delete (void *)value; }
+    ~TSItem() { delete value; }
 
     const char *value;
     TSItem *next;
