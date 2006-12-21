*** include/X3DTK/private/X3DSFNodeFunctor.h.orig	Sat Dec 16 15:21:18 2006
--- include/X3DTK/private/X3DSFNodeFunctor.h	Sat Dec 16 15:21:31 2006
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
