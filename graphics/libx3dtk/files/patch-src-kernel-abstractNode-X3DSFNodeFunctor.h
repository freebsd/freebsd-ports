*** src/kernel/abstractNode/X3DSFNodeFunctor.h.orig	Sat Dec 16 16:08:26 2006
--- src/kernel/abstractNode/X3DSFNodeFunctor.h	Sat Dec 16 16:09:15 2006
***************
*** 26,31 ****
--- 26,32 ----
  class X3DSFNodeFunctor
  {
  public:
+   virtual ~X3DSFNodeFunctor() {}
    virtual X3DAbstractNode *getNode(X3DAbstractNode const *N) = 0;
    virtual bool setNode(X3DAbstractNode *N, X3DAbstractNode *C) = 0;
    virtual bool removeNode(X3DAbstractNode *N, X3DAbstractNode *C) = 0;
