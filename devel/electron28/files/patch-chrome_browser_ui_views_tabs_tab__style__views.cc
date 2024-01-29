--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2023-10-19 19:58:07 UTC
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -490,7 +490,7 @@ float GM2TabStyleViews::GetCurrentActiveOpacity() cons
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 TabActive GM2TabStyleViews::GetApparentActiveState() const {
