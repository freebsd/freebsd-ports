commit 0946c6880def66bc0c611dad37140da3f126a6c3
Author: wmayer <wmayer@freecad.org>
Date:   Wed Sep 11 16:53:08 2024 +0200

    StartPage: Make sure to pass a container widget to the QScrollArea
    
    Fixes #16047: FreeBSD: Segfault in StartView::firstStartWidgetDismissed

diff --git src/Mod/Start/Gui/StartView.cpp src/Mod/Start/Gui/StartView.cpp
index 4667c8db72..086cec7c35 100644
--- src/Mod/Start/Gui/StartView.cpp
+++ src/Mod/Start/Gui/StartView.cpp
@@ -117,7 +117,11 @@ StartView::StartView(QWidget* parent)
 
     // First start page
     auto firstStartScrollArea = gsl::owner<QScrollArea*>(new QScrollArea());
-    auto firstStartRegion = gsl::owner<QHBoxLayout*>(new QHBoxLayout(firstStartScrollArea));
+    auto firstStartScrollWidget = gsl::owner<QWidget*>(new QWidget(firstStartScrollArea));
+    firstStartScrollArea->setWidget(firstStartScrollWidget);
+    firstStartScrollArea->setWidgetResizable(true);
+
+    auto firstStartRegion = gsl::owner<QHBoxLayout*>(new QHBoxLayout(firstStartScrollWidget));
     firstStartRegion->addStretch();
     auto firstStartWidget = gsl::owner<FirstStartWidget*>(new FirstStartWidget(this));
     connect(firstStartWidget,
