--- orbitcpp/idl-compiler/types/IDLStruct.h.orig	Fri Jun 20 14:36:07 2003
+++ orbitcpp/idl-compiler/types/IDLStruct.h	Fri Jun 20 14:36:26 2003
@@ -33,7 +33,7 @@
 #include "IDLCompound.h"
 #include "IDLCompoundSeqElem.h"
 
-class IDLStruct: public IDLCompound, public virtual IDLType, public IDLCompoundSeqElem
+class IDLStruct: public IDLCompound, public IDLCompoundSeqElem
 {
 public:
 	IDLStruct(const string &id,
