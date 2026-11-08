-- Implement the new pure virtual setImageBlendMode added to LowLevelGraphicsContext
-- in JUCE 9, so the demo's CanvasGeneratingContext is no longer abstract.
--- extras/NetworkGraphicsDemo/Source/SharedCanvas.h.orig	2026-08-05 19:49:26 UTC
+++ extras/NetworkGraphicsDemo/Source/SharedCanvas.h
@@ -371,6 +371,7 @@ class CanvasGeneratingContext final : public LowLevelG
     //==============================================================================
     void setFill (const FillType& fillType) override                { getState().fillType = fillType; }
     void setOpacity (float op) override                             { getState().fillType.setOpacity (op); }
+    void setImageBlendMode (BlendMode) override                     {}
     void setInterpolationQuality (Graphics::ResamplingQuality) override {}
 
     //==============================================================================
