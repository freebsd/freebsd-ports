*** src/X3DLoader/X3D_Creator.cpp.orig	Thu Sep 28 13:04:15 2006
--- src/X3DLoader/X3D_Creator.cpp	Thu Sep 28 13:04:34 2006
***************
*** 147,153 ****
    return CF;
  }
  
! Creator *X3DTK::X3D::joinCreator(Creator *N0, Creator *N1)
  {
    Creator *N = new Creator();
    
--- 147,153 ----
    return CF;
  }
  
! Creator *joinCreator(Creator *N0, Creator *N1)
  {
    Creator *N = new Creator();
    
