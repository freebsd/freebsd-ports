--- ui/zenoui/comctrl/zspinboxslider.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zspinboxslider.cpp
@@ -75,7 +75,7 @@ ZSpinBoxSlider::ZSpinBoxSlider(QWidget*
 
     pLayout->addWidget(m_pSpinbox);
     pLayout->addWidget(m_pSlider);
-    pLayout->setMargin(0);
+    pLayout->setContentsMargins(0, 0, 0, 0);
 
     connect(m_pSlider, &QSlider::valueChanged, this, [=](int value) {
         BlockSignalScope sp(m_pSpinbox);
