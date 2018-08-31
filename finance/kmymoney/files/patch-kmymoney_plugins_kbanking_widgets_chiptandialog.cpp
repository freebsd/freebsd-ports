From e5198a902996b27bf9abde0ad24af82d55ab5dc1 Mon Sep 17 00:00:00 2001
From: Luca Beltrame <lbeltrame@kde.org>
Date: Thu, 10 May 2018 09:35:34 +0200
Subject: [PATCH] Fix build with Qt 5.11

--- kmymoney/plugins/kbanking/widgets/chiptandialog.cpp.orig	2018-03-18 15:55:30 UTC
+++ kmymoney/plugins/kbanking/widgets/chiptandialog.cpp
@@ -28,6 +28,7 @@
 #include <QQuickView>
 #include <QQuickItem>
 #include <QPushButton>
+#include <QRegExpValidator>
 #include <QStandardPaths>
 
 #include <KLocalizedString>
