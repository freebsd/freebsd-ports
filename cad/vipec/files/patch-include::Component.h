--- ../include/Component.h.orig	Fri Mar 30 18:50:58 2001
+++ ../include/Component.h	Fri Aug 20 21:55:50 2004
@@ -93,6 +93,10 @@
 
   static int getNodeSize();
 
+  //Not implemented
+  Component( const Component& c );
+  Component& operator=( const Component& c );
+
 protected:
   virtual void drawSymbol(QPainter*) = 0;
   CircuitNode* addNode(int, int, bool isPortNode = FALSE, 
@@ -106,10 +110,6 @@
   void copyMemberData( Component& source );
 
 private:
-  //Not implemented
-  Component( const Component& c );
-  Component& operator=( const Component& c );
-
   void drawAttributes(QPainter* painter);
 
 protected:
