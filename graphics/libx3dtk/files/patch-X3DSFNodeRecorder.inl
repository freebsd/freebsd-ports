*** include/X3DTK/private/X3DSFNodeRecorder.inl.orig	Fri Aug 27 13:18:22 2004
--- include/X3DTK/private/X3DSFNodeRecorder.inl	Sat Oct 29 12:40:12 2005
***************
*** 1,3 ****
--- 1,5 ----
+ #include "X3DAbstractNodeForward.h"
+ 
  namespace X3DTK {
  
  template<class T, class V>
***************
*** 9,15 ****
  template<class T, class V>
  void SFNodeRecorder<T, V>::record(X3DAbstractNode *N) const
  {
!   SFType *type = N->getType();
  
    static_cast<T *>(N)->*_node = 0;
      
--- 11,17 ----
  template<class T, class V>
  void SFNodeRecorder<T, V>::record(X3DAbstractNode *N) const
  {
!   SFType *type = X3DAbstractNode_getType(N);
  
    static_cast<T *>(N)->*_node = 0;
      
