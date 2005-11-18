*** include/X3DTK/private/X3DMFNodeRecorder.inl.orig	Fri Aug 27 13:18:22 2004
--- include/X3DTK/private/X3DMFNodeRecorder.inl	Sat Oct 29 12:40:12 2005
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
  void MFNodeRecorder<T, V>::record(X3DAbstractNode *N) const
  {
!   SFType *type = N->getType();
      
    for (std::vector<std::pair<SFString, X3DMFNodeFunctor *> >::iterator it = type->nodesMap().begin(); it != type->nodesMap().end(); ++it)
    {
--- 11,17 ----
  template<class T, class V>
  void MFNodeRecorder<T, V>::record(X3DAbstractNode *N) const
  {
!   SFType *type = X3DAbstractNode_getType(N);
      
    for (std::vector<std::pair<SFString, X3DMFNodeFunctor *> >::iterator it = type->nodesMap().begin(); it != type->nodesMap().end(); ++it)
    {
