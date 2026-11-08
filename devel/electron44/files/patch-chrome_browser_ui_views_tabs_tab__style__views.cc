--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2026-08-24 20:59:34 UTC
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -589,7 +589,7 @@ float TabStyleViewsImpl::GetCurrentActiveOpacity() con
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 TabStyle::TabColors TabStyleViewsImpl::CalculateTargetColors() const {
