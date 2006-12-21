*** include/X3DTK/private/X3DNodeCloner.h.orig	Sat Dec 16 15:18:34 2006
--- include/X3DTK/private/X3DNodeCloner.h	Sat Dec 16 15:19:09 2006
***************
*** 24,29 ****
--- 24,30 ----
  class X3DNodeCloner
  {
  public:
+   virtual ~X3DNodeCloner() {}
    virtual SFNode create() const = 0;
  };
  
