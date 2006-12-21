*** src/kernel/abstractNode/X3DMemberFunctor.h.orig	Sat Dec 16 16:08:12 2006
--- src/kernel/abstractNode/X3DMemberFunctor.h	Sat Dec 16 16:08:54 2006
***************
*** 28,33 ****
--- 28,34 ----
  class X3DMemberFunctor
  {
  public:
+   virtual ~X3DMemberFunctor() {}
    virtual X3DField getValueOf(X3DAbstractNode const *N) const = 0;
    virtual void setValueOf(X3DAbstractNode *N, const X3DField &field) = 0;
  };
