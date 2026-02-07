This is just a hack, but the upstream response was "FreeBSD, whatevs".
In default ports builds Without this spurious qDebug(), the pointer
*reference gets weird addresses which don't correspond to any object
allocated by the program. This hack may be disguising a memory problem
higher up in the application.

--- src/libs/qmljs/qmljscontext.cpp.orig	2023-09-27 07:28:12 UTC
+++ src/libs/qmljs/qmljscontext.cpp
@@ -169,6 +169,7 @@ const Value *ReferenceContext::lookupReference(const V
 const Value *ReferenceContext::lookupReference(const Value *value)
 {
     const Reference *reference = value_cast<Reference>(value);
+    qDebug(); // some form of synchronisation happens here, preventing a crash
     if (!reference)
         return value;
 
