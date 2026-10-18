--- ui/zenoedit/panel/zenoblackboardpropwidget.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/panel/zenoblackboardpropwidget.cpp
@@ -22,8 +22,7 @@ ZenoBlackboardPropWidget::ZenoBlackboard
     pGroupLayout->setSpacing(10);
     PARAMS_INFO params = m_idx.data(ROLE_PARAMS_NO_DESC).value<PARAMS_INFO>();
     BLACKBOARD_INFO info = params["blackboard"].value.value<BLACKBOARD_INFO>();
-    UI_VECTYPE colorVec(3);
-    info.background.getRgbF(&colorVec[0], &colorVec[1], &colorVec[2]);
+    UI_VECTYPE colorVec{info.background.redF(), info.background.greenF(), info.background.blueF()};
     insertRow("background", PARAM_CONTROL::CONTROL_COLOR_VEC3F, QVariant::fromValue(colorVec), 0, pGroupLayout);
     insertRow("title", PARAM_CONTROL::CONTROL_MULTILINE_STRING, info.title, 1, pGroupLayout);
     //insertRow("content", PARAM_CONTROL::CONTROL_MULTILINE_STRING, info.content, 2, pGroupLayout);
