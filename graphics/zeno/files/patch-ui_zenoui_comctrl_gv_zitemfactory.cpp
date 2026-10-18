--- ui/zenoui/comctrl/gv/zitemfactory.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/gv/zitemfactory.cpp
@@ -259,8 +259,7 @@ namespace zenoui
                     {
                         pEditBtn->setProperty("color", color.name());
                         if (ctrl == CONTROL_COLOR_VEC3F) {
-                            UI_VECTYPE colorVec(3);
-                            color.getRgbF(&colorVec[0], &colorVec[1], &colorVec[2]);
+                            UI_VECTYPE colorVec{color.redF(), color.greenF(), color.blueF()};
                             cbSet.cbEditFinished(QVariant::fromValue<UI_VECTYPE>(colorVec));
                         }
                     }
