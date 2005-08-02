--- kmail/partNode.cpp.orig	Tue Aug  2 00:59:57 2005
+++ kmail/partNode.cpp	Tue Aug  2 01:01:06 2005
@@ -36,6 +36,7 @@
 #include "kmmimeparttree.h"
 #include <mimelib/utility.h>
 #include <qregexp.h>
+#include <kasciistricmp.h>
 
 /*
   ===========================================================================
@@ -414,7 +415,7 @@
 partNode* partNode::findNodeForDwPart( DwBodyPart* part )
 {
     partNode* found = 0;
-    if( dwPart()->partId() == part->partId() )
+    if( kasciistricmp( dwPart()->partId(), part->partId() ) == 0 )
         return this;
     if( mChild )
         found = mChild->findNodeForDwPart( part );
