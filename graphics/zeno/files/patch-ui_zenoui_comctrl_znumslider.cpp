--- ui/zenoui/comctrl/znumslider.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/znumslider.cpp
@@ -22,7 +22,7 @@ ZNumSlider::ZNumSlider(QVector<qreal> sc
         pLabel->setAttribute(Qt::WA_TranslucentBackground, true);
         m_labels.append(pLabel);
     }
-    pLayout->setMargin(0);
+    pLayout->setContentsMargins(0, 0, 0, 0);
     pLayout->setSpacing(0);
     setLayout(pLayout);
 
