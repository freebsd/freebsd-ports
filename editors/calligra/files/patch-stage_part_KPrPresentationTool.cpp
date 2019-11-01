From 70be8c437406a74c1ec560d1f2cc538e8ede2b8d Mon Sep 17 00:00:00 2001
From: Dan Leinir Turthra Jensen <admin@leinir.dk>
Date: Tue, 19 Jun 2018 09:52:41 +0100
Subject: [PATCH] Missing include for QFrame

This was causing build breakage on the binary factory

--- stage/part/KPrPresentationTool.cpp.orig	2018-01-26 09:24:44 UTC
+++ stage/part/KPrPresentationTool.cpp
@@ -32,6 +32,7 @@
 #include <QDesktopServices>
 #include <QUrl>
 #include <QDBusConnection>
+#include <QFrame>
 
 #include <KoShape.h>
 #include <KoShapeManager.h>
