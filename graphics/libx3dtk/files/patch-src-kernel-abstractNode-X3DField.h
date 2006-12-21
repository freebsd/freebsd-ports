*** src/kernel/abstractNode/X3DField.h.orig	Sat Dec 16 16:04:52 2006
--- src/kernel/abstractNode/X3DField.h	Sat Dec 16 16:05:59 2006
***************
*** 55,60 ****
--- 55,61 ----
  class X3DFieldLoader
  {
  public:
+   virtual ~X3DFieldLoader() {}
    virtual void load(X3DField &field, const SFString &value) = 0;
  };
  
***************
*** 69,74 ****
--- 70,76 ----
  class X3DFieldWriter
  {
  public:
+   virtual ~X3DFieldWriter() {}
    virtual SFString write(const X3DField &field) = 0;
    virtual void writeToFile(SFString &output, const SFString &name, const X3DField &field, const SFString &init) = 0;
  };
