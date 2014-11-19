# HG changeset patch
# User Ehsan Akhgari <ehsan@mozilla.com>
# Date 1308340787 14400
# Node ID c0e8643e8e60d1c98bff30c78e034f991f75c191
# Parent  284ebc48b2cb8e35dc04482ede700e717d8d214f
Bug 662962 - Silence the clang warnings issued because of alignment requirements increase when compiling jsscript.h; r=Waldo

--- deps/mozilla/js/src/jsscript.h.orig	2011-04-01 06:08:36.000000000 +1100
+++ deps/mozilla/js/src/jsscript.h	2013-05-26 00:23:16.202260566 +1000
@@ -496,32 +496,32 @@
 
     JSObjectArray *objects() {
         JS_ASSERT(isValidOffset(objectsOffset));
-        return (JSObjectArray *)((uint8 *) (this + 1) + objectsOffset);
+        return reinterpret_cast<JSObjectArray *>(uintptr_t(this + 1) + objectsOffset);
     }
 
     JSUpvarArray *upvars() {
         JS_ASSERT(isValidOffset(upvarsOffset));
-        return (JSUpvarArray *) ((uint8 *) (this + 1) + upvarsOffset);
+        return reinterpret_cast<JSUpvarArray *>(uintptr_t(this + 1) + upvarsOffset);
     }
 
     JSObjectArray *regexps() {
         JS_ASSERT(isValidOffset(regexpsOffset));
-        return (JSObjectArray *) ((uint8 *) (this + 1) + regexpsOffset);
+        return reinterpret_cast<JSObjectArray *>(uintptr_t(this + 1) + regexpsOffset);
     }
 
     JSTryNoteArray *trynotes() {
         JS_ASSERT(isValidOffset(trynotesOffset));
-        return (JSTryNoteArray *) ((uint8 *) (this + 1) + trynotesOffset);
+        return reinterpret_cast<JSTryNoteArray *>(uintptr_t(this + 1) + trynotesOffset);
     }
 
     js::GlobalSlotArray *globals() {
         JS_ASSERT(isValidOffset(globalsOffset));
-        return (js::GlobalSlotArray *) ((uint8 *) (this + 1) + globalsOffset);
+        return reinterpret_cast<js::GlobalSlotArray *>(uintptr_t(this + 1) + globalsOffset);
     }
 
     JSConstArray *consts() {
         JS_ASSERT(isValidOffset(constOffset));
-        return (JSConstArray *) ((uint8 *) (this + 1) + constOffset);
+        return reinterpret_cast<JSConstArray *>(uintptr_t(this + 1) + constOffset);
     }
 
     JSAtom *getAtom(size_t index) {
