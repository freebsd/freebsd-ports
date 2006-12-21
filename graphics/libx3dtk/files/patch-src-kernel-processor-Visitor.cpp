*** src/kernel/processor/Visitor.cpp.orig	Sun Dec 17 12:45:21 2006
--- src/kernel/processor/Visitor.cpp	Sun Dec 17 12:46:14 2006
***************
*** 160,166 ****
    return LF;
  }
  
! Visitor *X3DTK::joinVisitors(Visitor *N0, Visitor *N1)
  {
    Visitor *N = new Visitor();
    
--- 160,167 ----
    return LF;
  }
  
! namespace X3DTK {
! Visitor *joinVisitors(Visitor *N0, Visitor *N1)
  {
    Visitor *N = new Visitor();
    
***************
*** 171,174 ****
--- 172,176 ----
      N->setComponentVisitor(*j);
    
    return N;  
+ }
  }
