*** include/X3DTK/private/X3DLoader.h.orig	Sat Dec 16 15:22:27 2006
--- include/X3DTK/private/X3DLoader.h	Sat Dec 16 15:22:36 2006
***************
*** 73,79 ****
    void setComponentVisitorForFileValidator(X3DComponentVisitor *component);
    /// Sets the FileValidator. If there is already a creator recorded for this component,
    /// then it is deleted and replaced by the new one.
!   void X3DLoader::setFileValidator(X3D::FileValidator *fileValidator);
    
  protected:
    /// Creator.
--- 73,79 ----
    void setComponentVisitorForFileValidator(X3DComponentVisitor *component);
    /// Sets the FileValidator. If there is already a creator recorded for this component,
    /// then it is deleted and replaced by the new one.
!   void setFileValidator(X3D::FileValidator *fileValidator);
    
  protected:
    /// Creator.
