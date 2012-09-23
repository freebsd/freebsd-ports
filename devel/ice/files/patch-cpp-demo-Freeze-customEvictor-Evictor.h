--- cpp.orig/demo/Freeze/customEvictor/Evictor.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/demo/Freeze/customEvictor/Evictor.h	2012-09-10 11:43:58.000000000 +0200
@@ -66,6 +66,7 @@ class Evictor : public Ice::ServantLocator
 public:
     
     Evictor(CurrentDatabase&, int);
+    virtual ~Evictor() ICE_NOEXCEPT_TRUE {};
     
     virtual Ice::ObjectPtr locate(const Ice::Current&, Ice::LocalObjectPtr&);
     virtual void finished(const Ice::Current&, const Ice::ObjectPtr&, const Ice::LocalObjectPtr&);
