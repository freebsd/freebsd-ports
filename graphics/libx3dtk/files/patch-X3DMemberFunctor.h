*** include/X3DTK/private/X3DMemberFunctor.h.orig	Sat Dec 16 15:20:40 2006
--- include/X3DTK/private/X3DMemberFunctor.h	Sat Dec 16 15:21:00 2006
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
