*** include/X3DTK/private/X3D_Scene.h.orig	Sat Dec 16 16:25:53 2006
--- include/X3DTK/private/X3D_Scene.h	Sat Dec 16 16:28:11 2006
***************
*** 36,43 ****
  
  class Scene : public X3DGroupingNode, public X3DBoundedObject
  {
!   friend class ProcessHistory;
!   friend class X3DRoute;
  public:
    /// Constructor.
    Scene();
--- 36,43 ----
  
  class Scene : public X3DGroupingNode, public X3DBoundedObject
  {
!   friend class ::X3DTK::ProcessHistory;
!   friend class ::X3DTK::X3DRoute;
  public:
    /// Constructor.
    Scene();
