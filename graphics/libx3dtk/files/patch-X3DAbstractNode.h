*** include/X3DTK/private/X3DAbstractNode.h.orig	Fri Aug 27 13:18:33 2004
--- include/X3DTK/private/X3DAbstractNode.h	Sat Oct 29 12:40:12 2005
***************
*** 133,138 ****
--- 133,148 ----
    bool removeParent(const SFNode &N);
  };
  
+ inline void X3DAbstractNode_addParentToChild(SFNode parent, SFNode child) {
+   X3DAbstractNode::addParentToChild(parent,child);
+ }
+ inline void X3DAbstractNode_removeParentFromChild(SFNode parent, SFNode child) {
+   X3DAbstractNode::removeParentFromChild(parent,child);
+ }
+ inline SFType * X3DAbstractNode_getType(X3DAbstractNode * node) {
+   return node->getType();
+ }
+ 
  }
  
  #include "X3DAbstractNode.inl"
