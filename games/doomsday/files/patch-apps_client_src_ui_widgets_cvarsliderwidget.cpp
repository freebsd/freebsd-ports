--- apps/client/src/ui/widgets/cvarsliderwidget.cpp.orig	2023-06-26 18:09:55 UTC
+++ apps/client/src/ui/widgets/cvarsliderwidget.cpp
@@ -87,6 +87,6 @@ void CVarSliderWidget::setCVarValueFromWidget()
     }
     else
     {
-        CVar_SetInteger(d->var(), round<int>(value()));
+        CVar_SetInteger(d->var(), de::round<int>(value()));
     }
 }
