--- qtgui/src/gui/graphnameview.cpp.orig	Fri Dec 22 15:47:05 2006
+++ qtgui/src/gui/graphnameview.cpp	Fri Dec 22 15:47:31 2006
@@ -266,7 +266,7 @@
       m_textListener->textChanged(1,newStatus.c_str());
     }
 
-    virtual void GraphItem::propertySelected(int id)
+    virtual void propertySelected(int id)
     {
       switch(id)
 	{
@@ -428,7 +428,7 @@
       m_textListener->textChanged(1,newStatus.c_str());
     }
 
-    void SnapItem::propertySelected(int id)
+    void propertySelected(int id)
     {
       switch(id)
 	{
