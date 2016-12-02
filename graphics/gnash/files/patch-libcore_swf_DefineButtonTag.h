$NetBSD: patch-libcore_swf_DefineButtonTag.h,v 1.2 2013/12/15 19:42:04 joerg Exp $

--- libcore/swf/DefineButtonTag.h.orig	2012-01-19 19:17:48.000000000 +0000
+++ libcore/swf/DefineButtonTag.h
@@ -98,7 +98,7 @@ public:
     /// A ButtonRecord is invalid if it refers to a DisplayObject
     /// which has not been defined.
     bool valid() const {
-        return (_definitionTag);
+        return bool(_definitionTag);
     }
 
 private:
@@ -157,8 +157,6 @@ public:
         return (_conditions & KEYPRESS);
     }
 
-private:
-
     /// Return the keycode triggering this action
     //
     /// Return 0 if no key is supposed to trigger us
@@ -166,6 +164,8 @@ private:
         return (_conditions & KEYPRESS) >> 9;
     }
 
+private:
+
     enum Condition
     {
         IDLE_TO_OVER_UP = 1 << 0,
