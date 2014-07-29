--- cmn/physical.h.orig	Wed Jan 19 12:54:08 2000
+++ cmn/physical.h	Mon Nov  3 21:36:14 2003
@@ -93,7 +93,7 @@
    CLASSNAME::CLASSNAME(InStreamP in,const CLASSNAME ## Context &cx, \
                          CLASSNAME ## Xdata &x_data, \
                          WorldP w,LocatorP l) \
-   : PARENT(in,cx. ## parent ## Context,x_data,w,l) 
+   : PARENT(in,cx. parent ## Context,x_data,w,l) 
 
 // Used by internal nodes and leaves.
 #define DEFINE_UPDATE_FROM_STREAM(CLASSNAME,PARENT) \
