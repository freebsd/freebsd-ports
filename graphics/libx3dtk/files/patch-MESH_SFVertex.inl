*** include/X3DTK/private/MESH_SFVertex.inl.orig	Sat Dec 16 15:54:33 2006
--- include/X3DTK/private/MESH_SFVertex.inl	Sat Dec 16 15:55:20 2006
***************
*** 46,58 ****
  #endif
  
  template<class MData, class VData, class EData, class FData, bool RW>
! SFTemplateVertex<MData, VData, EData, FData, RW>::SFTemplateVertex<MData, VData, EData, FData, RW>(unsigned int i)
  : BaseSFVertex(i)
  {
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
! SFTemplateVertex<MData, VData, EData, FData, RW>::~SFTemplateVertex<MData, VData, EData, FData, RW>()
  {
  }
  
--- 46,58 ----
  #endif
  
  template<class MData, class VData, class EData, class FData, bool RW>
! SFTemplateVertex<MData, VData, EData, FData, RW>::SFTemplateVertex(unsigned int i)
  : BaseSFVertex(i)
  {
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
! SFTemplateVertex<MData, VData, EData, FData, RW>::~SFTemplateVertex()
  {
  }
  
