*** include/X3DTK/private/Signal.h.orig	Sat Dec 16 16:51:16 2006
--- include/X3DTK/private/Signal.h	Sat Dec 16 16:51:52 2006
***************
*** 44,49 ****
--- 44,50 ----
  class Signal
  {
  public:
+   virtual ~Signal() {}
    virtual void transmit() = 0;
  
  #ifdef TEMPLATE_SPECIALIZATION_SUPPORTED
