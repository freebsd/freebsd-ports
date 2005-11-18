*** include/X3DTK/private/MESH_SFDirectEdge.inl.orig	Fri Aug 27 13:18:22 2004
--- include/X3DTK/private/MESH_SFDirectEdge.inl	Sat Oct 29 12:40:12 2005
***************
*** 19,67 ****
  template<class MData, class VData, class EData, class FData, bool RW>
  SFTemplateVertex<MData, VData, EData, FData, RW> *SFTemplateDirectEdge<MData, VData, EData, FData, RW>::getFromVertex() const 
  {
!   return _edgeContent->getFromVertex();
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  SFTemplateVertex<MData, VData, EData, FData, RW> *SFTemplateDirectEdge<MData, VData, EData, FData, RW>::getToVertex() const 
  {
!   return _edgeContent->getToVertex();
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  const typename SFTemplateDirectEdge<MData, VData, EData, FData, RW>::MFFace &SFTemplateDirectEdge<MData, VData, EData, FData, RW>::getLeftFaces() const 
  {
!   return _edgeContent->get1Faces();
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  const typename SFTemplateDirectEdge<MData, VData, EData, FData, RW>::MFFace &SFTemplateDirectEdge<MData, VData, EData, FData, RW>::getRightFaces() const 
  {
!   return _edgeContent->get2Faces();
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  void SFTemplateDirectEdge<MData, VData, EData, FData, RW>::addLeftFace(SFTemplateFace<MData, VData, EData, FData, RW> *face) 
  {
!   _edgeContent->add1Face(face);
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  void SFTemplateDirectEdge<MData, VData, EData, FData, RW>::addRightFace(SFTemplateFace<MData, VData, EData, FData, RW> *face) 
  {
!   _edgeContent->add2Face(face);
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  void SFTemplateDirectEdge<MData, VData, EData, FData, RW>::removeLeftFace(SFTemplateFace<MData, VData, EData, FData, RW> *face) 
  {
!   _edgeContent->remove1Face(face);
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  void SFTemplateDirectEdge<MData, VData, EData, FData, RW>::removeRightFace(SFTemplateFace<MData, VData, EData, FData, RW> *face) 
  {
!   _edgeContent->remove2Face(face);
  }
  
  }
--- 19,67 ----
  template<class MData, class VData, class EData, class FData, bool RW>
  SFTemplateVertex<MData, VData, EData, FData, RW> *SFTemplateDirectEdge<MData, VData, EData, FData, RW>::getFromVertex() const 
  {
!   return SFTemplateDirectEdge<MData, VData, EData, FData, RW>::_edgeContent->getFromVertex();
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  SFTemplateVertex<MData, VData, EData, FData, RW> *SFTemplateDirectEdge<MData, VData, EData, FData, RW>::getToVertex() const 
  {
!   return SFTemplateDirectEdge<MData, VData, EData, FData, RW>::_edgeContent->getToVertex();
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  const typename SFTemplateDirectEdge<MData, VData, EData, FData, RW>::MFFace &SFTemplateDirectEdge<MData, VData, EData, FData, RW>::getLeftFaces() const 
  {
!   return SFTemplateDirectEdge<MData, VData, EData, FData, RW>::_edgeContent->get1Faces();
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  const typename SFTemplateDirectEdge<MData, VData, EData, FData, RW>::MFFace &SFTemplateDirectEdge<MData, VData, EData, FData, RW>::getRightFaces() const 
  {
!   return SFTemplateDirectEdge<MData, VData, EData, FData, RW>::_edgeContent->get2Faces();
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  void SFTemplateDirectEdge<MData, VData, EData, FData, RW>::addLeftFace(SFTemplateFace<MData, VData, EData, FData, RW> *face) 
  {
!   SFTemplateDirectEdge<MData, VData, EData, FData, RW>::_edgeContent->add1Face(face);
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  void SFTemplateDirectEdge<MData, VData, EData, FData, RW>::addRightFace(SFTemplateFace<MData, VData, EData, FData, RW> *face) 
  {
!   SFTemplateDirectEdge<MData, VData, EData, FData, RW>::_edgeContent->add2Face(face);
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  void SFTemplateDirectEdge<MData, VData, EData, FData, RW>::removeLeftFace(SFTemplateFace<MData, VData, EData, FData, RW> *face) 
  {
!   SFTemplateDirectEdge<MData, VData, EData, FData, RW>::_edgeContent->remove1Face(face);
  }
  
  template<class MData, class VData, class EData, class FData, bool RW>
  void SFTemplateDirectEdge<MData, VData, EData, FData, RW>::removeRightFace(SFTemplateFace<MData, VData, EData, FData, RW> *face) 
  {
!   SFTemplateDirectEdge<MData, VData, EData, FData, RW>::_edgeContent->remove2Face(face);
  }
  
  }
