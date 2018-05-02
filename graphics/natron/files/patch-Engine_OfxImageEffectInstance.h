--- Engine/OfxImageEffectInstance.h.orig	2017-08-13 15:26:35 UTC
+++ Engine/OfxImageEffectInstance.h
@@ -109,7 +109,7 @@ class OfxImageEffectInstance (public)
     //
     // live parameters
     //
-    virtual const std::vector<std::string>& getUserCreatedPlanes() const OVERRIDE FINAL;
+    virtual const std::vector<std::string>& getUserCreatedPlanes() const FINAL;
 
     // The size of the current project in canonical coordinates.
     // The size of a project is a sub set of the kOfxImageEffectPropProjectExtent. For example a
