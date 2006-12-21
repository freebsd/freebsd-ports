*** include/X3DTK/private/X3DMFNodeFunctor.h.orig	Sat Dec 16 15:21:47 2006
--- include/X3DTK/private/X3DMFNodeFunctor.h	Sat Dec 16 15:22:02 2006
***************
*** 26,31 ****
--- 26,32 ----
  class X3DMFNodeFunctor
  {
  public:
+   virtual ~X3DMFNodeFunctor() {}
    virtual const MFNode &getNodes(X3DAbstractNode const *N) = 0;
    virtual bool addNode(X3DAbstractNode *N, X3DAbstractNode *C) = 0;
    virtual bool removeNode(X3DAbstractNode *N, X3DAbstractNode *C) = 0;
