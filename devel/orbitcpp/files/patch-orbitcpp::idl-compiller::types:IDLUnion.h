--- orbitcpp/idl-compiler/types/IDLUnion.h.orig	Fri Jun 20 15:05:07 2003
+++ orbitcpp/idl-compiler/types/IDLUnion.h	Fri Jun 20 15:05:33 2003
@@ -34,7 +34,7 @@
 #include "IDLCompoundSeqElem.h"
 //#include "language.h"
 
-class IDLUnion: public virtual IDLType, public IDLScope, public IDLCompoundSeqElem
+class IDLUnion: public IDLScope, public IDLCompoundSeqElem
 {
 	const IDLUnionDiscriminator &m_discriminator;
 
