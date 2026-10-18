--- ui/zenoui/comctrl/zwidgetfactory.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zwidgetfactory.cpp
@@ -157,8 +157,7 @@ namespace zenoui
                     {
                         pBtn->setStyleSheet(QString("background-color:%1; border:0;").arg(color.name()));
                         if (ctrl == CONTROL_COLOR_VEC3F) {
-                            UI_VECTYPE colorVec(3);
-                            color.getRgbF(&colorVec[0], &colorVec[1], &colorVec[2]);
+                            UI_VECTYPE colorVec{color.redF(), color.greenF(), color.blueF()};
                             cbSet.cbEditFinished(QVariant::fromValue<UI_VECTYPE>(colorVec));
                         }
                     }
