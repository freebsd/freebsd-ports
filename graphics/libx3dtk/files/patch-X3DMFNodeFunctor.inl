*** include/X3DTK/private/X3DMFNodeFunctor.inl.orig	Fri Aug 27 13:18:22 2004
--- include/X3DTK/private/X3DMFNodeFunctor.inl	Sat Oct 29 12:40:12 2005
***************
*** 20,26 ****
    if (dynamic_cast<V *>(C) != 0)
    {
      (static_cast<T *>(N)->*_nodes).push_back(C);
!     X3DAbstractNode::addParentToChild(N, C);
      return true;
    }
    
--- 20,26 ----
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
--- 35,41 ----
    
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
--- 51,57 ----
      MFNode &nodes = (static_cast<T *>(N)->*_nodes);
  
      for (MFNode::const_iterator it = nodes.begin(); it != nodes.end(); ++it)
!       X3DAbstractNode_removeParentFromChild(N, *it);
     
      nodes.clear();  
    }  
