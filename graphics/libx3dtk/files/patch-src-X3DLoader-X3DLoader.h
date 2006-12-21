*** src/X3DLoader/X3DLoader.h.orig	Sat Dec 16 16:30:37 2006
--- src/X3DLoader/X3DLoader.h	Sat Dec 16 16:30:50 2006
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
