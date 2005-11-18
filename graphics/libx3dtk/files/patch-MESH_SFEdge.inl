*** include/X3DTK/private/MESH_SFEdge.inl.orig	Fri Aug 27 13:18:22 2004
--- include/X3DTK/private/MESH_SFEdge.inl	Sat Oct 29 12:40:12 2005
***************
*** 57,70 ****
  template<class F>  
  F &SFTemplateEdge<MData, VData, EData, FData, RW>::getData()
  {
!   return _data.template get<F, false>();
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  template<class F>  
  F &SFTemplateEdge<MData, VData, EData, FData, RW>::ogetData()
  {
!   return _data.template get<F, true>();
  }
  #endif
  
--- 57,70 ----
  template<class F>  
  F &SFTemplateEdge<MData, VData, EData, FData, RW>::getData()
  {
!   return SFTemplateEdge<MData, VData, EData, FData, RW>::_data.template get<F, false>();
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  template<class F>  
  F &SFTemplateEdge<MData, VData, EData, FData, RW>::ogetData()
  {
!   return SFTemplateEdge<MData, VData, EData, FData, RW>::_data.template get<F, true>();
  }
  #endif
  
