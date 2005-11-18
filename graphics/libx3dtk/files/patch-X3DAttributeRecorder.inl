*** include/X3DTK/private/X3DAttributeRecorder.inl.orig	Fri Aug 27 13:18:22 2004
--- include/X3DTK/private/X3DAttributeRecorder.inl	Sat Oct 29 12:40:12 2005
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
  void AttributeRecorder<T, V>::record(X3DAbstractNode *N) const
  {
!   SFType *type = N->getType();
    
    std::map<SFString, FieldManager>::iterator it = type->attributesMap().find(_name);
    if (it == type->attributesMap().end())
--- 11,17 ----
  template<class T, class V>
  void AttributeRecorder<T, V>::record(X3DAbstractNode *N) const
  {
!   SFType *type = X3DAbstractNode_getType(N);
    
    std::map<SFString, FieldManager>::iterator it = type->attributesMap().find(_name);
    if (it == type->attributesMap().end())
