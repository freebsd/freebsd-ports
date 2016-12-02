$NetBSD: patch-libcore_DragState.h,v 1.1 2014/08/19 13:39:24 joerg Exp $

--- libcore/DragState.h.orig	2014-08-19 11:01:44.000000000 +0000
+++ libcore/DragState.h
@@ -60,7 +60,7 @@ public:
     boost::int32_t yOffset() const { return _yoffset; }
 
     bool hasBounds() const {
-        return (_bounds);
+        return bool(_bounds);
     }
 
     /// \brief
