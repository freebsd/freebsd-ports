*** src/kernel/abstractNode/X3DSFNodeFunctor.inl.orig	Sat Oct 29 13:11:29 2005
--- src/kernel/abstractNode/X3DSFNodeFunctor.inl	Sat Oct 29 13:11:55 2005
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
    
--- 17,25 ----
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
--- 31,37 ----
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
--- 44,50 ----
  {
    if (dynamic_cast<T *>(N) != 0)
    {
!     X3DAbstractNode_removeParentFromChild(N, static_cast<T *>(N)->*_node);
      static_cast<T *>(N)->*_node = 0;
    }  
  }
