--- ui/zenoui/ColorEditor/ColorEditor.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/ColorEditor/ColorEditor.cpp
@@ -6,7 +6,6 @@
 #include <QCheckBox>
 #include <QCursor>
 #include <QDebug>
-#include <QDesktopWidget>
 #include <QDialogButtonBox>
 #include <QDrag>
 #include <QGridLayout>
@@ -637,7 +636,7 @@ public:
         slider->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
         auto layout = new QHBoxLayout(parent);
         layout->setAlignment(Qt::AlignLeft);
-        layout->setMargin(0);
+        layout->setContentsMargins(0, 0, 0, 0);
         layout->addWidget(text, 1);
         layout->addWidget(spinbox, 2);
         layout->addWidget(slider, 7);
@@ -782,7 +781,7 @@ void ColorButton::mouseMoveEvent(QMouseE
             drg->setPixmap(pix);
             drg->exec(Qt::CopyAction);
             // need let pushbutton release
-            QMouseEvent event(QEvent::MouseButtonRelease, e->pos(), Qt::LeftButton, Qt::LeftButton, 0);
+            QMouseEvent event(QEvent::MouseButtonRelease, e->pos(), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
             QApplication::sendEvent(this, &event);
         }
     }
@@ -831,7 +830,7 @@ public:
         layout = new QGridLayout(scrollWidget);
         layout->setAlignment(Qt::AlignTop);
         layout->setSpacing(0);
-        layout->setMargin(0);
+        layout->setContentsMargins(0, 0, 0, 0);
 
         parent->setWidget(scrollWidget);
     }
@@ -992,7 +991,7 @@ public:
 
         auto layout = new QHBoxLayout(parent);
         layout->setSpacing(0);
-        layout->setMargin(0);
+        layout->setContentsMargins(0, 0, 0, 0);
         layout->addWidget(pbtnPrevious);
         layout->addWidget(pbtnCurrent);
     }
@@ -1051,9 +1050,9 @@ public:
         factorSpinbox->setButtonSymbols(QAbstractSpinBox::NoButtons);
 
         auto layout = new QGridLayout(parent);
-        layout->setMargin(0);
+        layout->setContentsMargins(0, 0, 0, 0);
         hlayout = new QHBoxLayout();
-        hlayout->setMargin(0);
+        hlayout->setContentsMargins(0, 0, 0, 0);
         hlayout->setSpacing(0);
         layout->addLayout(hlayout, 0, 0, 1, 9);
         layout->addWidget(switchBtn, 0, 9, 1, 1);
@@ -1203,16 +1202,15 @@ public:
 
     void grabFullScreen()
     {
-        const QDesktopWidget* desktop = QApplication::desktop();
-        const QPixmap pixmap = QApplication::primaryScreen()->grabWindow(desktop->winId(), desktop->pos().x(), desktop->pos().y(),
-                                                                         desktop->width(), desktop->height());
+        const QRect desktop = QApplication::primaryScreen()->virtualGeometry();
+        const QPixmap pixmap = QApplication::primaryScreen()->grabWindow(0, desktop.x(), desktop.y(),
+                                                                         desktop.width(), desktop.height());
         fullScreenImg = pixmap.toImage();
     }
 
     QRect getScreenRect() const
     {
-        const QDesktopWidget* desktop = QApplication::desktop();
-        return QRect(desktop->pos(), desktop->size());
+        return QApplication::primaryScreen()->virtualGeometry();
     }
 
     QColor getColorAt(QPoint p) const 
@@ -1255,8 +1253,7 @@ ColorPicker::~ColorPicker() = default;
 QColor ColorPicker::grabScreenColor(QPoint p) const
 {
     // not use now, just make screenshot and get color from it
-    const QDesktopWidget* desktop = QApplication::desktop();
-    const QPixmap pixmap = QApplication::primaryScreen()->grabWindow(desktop->winId(), p.x(), p.y(), 1, 1);
+    const QPixmap pixmap = QApplication::primaryScreen()->grabWindow(0, p.x(), p.y(), 1, 1);
     QImage i = pixmap.toImage();
     return i.pixel(0, 0);
 }
@@ -1493,7 +1490,7 @@ public:
 
         auto previewWidget = new QWidget(parent);
         auto previewLayout = new QHBoxLayout(previewWidget);
-        previewLayout->setMargin(0);
+        previewLayout->setContentsMargins(0, 0, 0, 0);
         previewLayout->addWidget(preview);
         previewLayout->addWidget(pickerBtn);
 
@@ -1574,7 +1571,7 @@ public:
         connect(cancleBtn, &QPushButton::clicked, parent, &QDialog::reject);
 
         auto layout = new QVBoxLayout(parent);
-        layout->setMargin(5);
+        layout->setContentsMargins(5, 5, 5, 5);
         layout->addWidget(mainSplitter);
         layout->addWidget(buttons);
     }
