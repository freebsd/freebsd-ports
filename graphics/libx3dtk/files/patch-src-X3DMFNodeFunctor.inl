*** src/kernel/abstractNode/X3DMFNodeFunctor.inl.orig	Sat Oct 29 13:12:06 2005
--- src/kernel/abstractNode/X3DMFNodeFunctor.inl	Sat Oct 29 13:13:23 2005
***************
*** 1,3 ****
--- 1,4 ----
+ #include "X3DAbstractNodeForward.h"
  #include <typeinfo>
  
  namespace X3DTK {
***************
*** 20,26 ****
    if (dynamic_cast<V *>(C) != 0)
    {
      (static_cast<T *>(N)->*_nodes).push_back(C);
!     X3DAbstractNode::addParentToChild(N, C);
      return true;
    }
    
--- 21,27 ----
    if (dynamic_cast<V *>(C) != 0)
    {
      (static_cast<T *>(N)->*_nodes).push_back(C);
!     X3DAbstractNode_addParentToChild(N, C);
      return true;
    }
    
***************
*** 35,41 ****
    
    if (res != nodes.end())
    {
!     X3DAbstractNode::removeParentFromChild(N, C);
      nodes.erase(res);
      return true;
    }
--- 36,42 ----
    
    if (res != nodes.end())
    {
!     X3DAbstractNode_removeParentFromChild(N, C);
      nodes.erase(res);
      return true;
    }
***************
*** 51,57 ****
      MFNode &nodes = (static_cast<T *>(N)->*_nodes);
  
      for (MFNode::const_iterator it = nodes.begin(); it != nodes.end(); ++it)
!       X3DAbstractNode::removeParentFromChild(N, *it);
     
      nodes.clear();  
    }  
--- 52,58 ----
      MFNode &nodes = (static_cast<T *>(N)->*_nodes);
  
      for (MFNode::const_iterator it = nodes.begin(); it != nodes.end(); ++it)
!       X3DAbstractNode_removeParentFromChild(N, *it);
     
      nodes.clear();  
    }  
