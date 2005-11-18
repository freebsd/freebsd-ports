*** include/X3DTK/private/X3DSFNodeFunctor.inl.orig	Fri Aug 27 13:18:22 2004
--- include/X3DTK/private/X3DSFNodeFunctor.inl	Sat Oct 29 12:40:12 2005
***************
*** 1,3 ****
--- 1,5 ----
+ #include "X3DAbstractNodeForward.h"
+ 
  namespace X3DTK {
  
  template<class T, class V>
***************
*** 17,25 ****
  {
    if (dynamic_cast<V *>(C) != 0)
    {
!     X3DAbstractNode::removeParentFromChild(N, static_cast<T *>(N)->*_node);
      static_cast<T *>(N)->*_node = static_cast<V *>(C);
!     X3DAbstractNode::addParentToChild(N, static_cast<T *>(N)->*_node);
      return true;
    }
    
--- 19,27 ----
  {
    if (dynamic_cast<V *>(C) != 0)
    {
!     X3DAbstractNode_removeParentFromChild(N, static_cast<T *>(N)->*_node);
      static_cast<T *>(N)->*_node = static_cast<V *>(C);
!     X3DAbstractNode_addParentToChild(N, static_cast<T *>(N)->*_node);
      return true;
    }
    
***************
*** 31,37 ****
  {
    if (C == static_cast<T *>(N)->*_node)
    {
!     X3DAbstractNode::removeParentFromChild(N, static_cast<T *>(N)->*_node);
      static_cast<T *>(N)->*_node = 0;
      return true;
    }
--- 33,39 ----
  {
    if (C == static_cast<T *>(N)->*_node)
    {
!     X3DAbstractNode_removeParentFromChild(N, static_cast<T *>(N)->*_node);
      static_cast<T *>(N)->*_node = 0;
      return true;
    }
***************
*** 44,50 ****
  {
    if (dynamic_cast<T *>(N) != 0)
    {
!     X3DAbstractNode::removeParentFromChild(N, static_cast<T *>(N)->*_node);
      static_cast<T *>(N)->*_node = 0;
    }  
  }
--- 46,52 ----
  {
    if (dynamic_cast<T *>(N) != 0)
    {
!     X3DAbstractNode_removeParentFromChild(N, static_cast<T *>(N)->*_node);
      static_cast<T *>(N)->*_node = 0;
    }  
  }
