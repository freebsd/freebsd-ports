https://bugzilla.mozilla.org/show_bug.cgi?id=1644600

--- js/public/StructuredClone.h.orig	2021-02-17 07:48:59 UTC
+++ js/public/StructuredClone.h
@@ -381,7 +381,7 @@ enum OwnTransferablePolicy {
 namespace js {
 class SharedArrayRawBuffer;
 
-class SharedArrayRawBufferRefs {
+class JS_PUBLIC_API SharedArrayRawBufferRefs {
  public:
   SharedArrayRawBufferRefs() = default;
   SharedArrayRawBufferRefs(SharedArrayRawBufferRefs&& other) = default;
