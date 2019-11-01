From 0c5430697bdcf41a45046107b28014e40c49a11a Mon Sep 17 00:00:00 2001
From: David Faure <faure@kde.org>
Date: Tue, 23 Jul 2019 13:02:34 +0200
Subject: Fix compilation with Qt 5.13 (missing include)

--- sheets/plugins/calendar/CalendarToolWidget.cpp.orig	2018-01-26 09:24:44 UTC
+++ sheets/plugins/calendar/CalendarToolWidget.cpp
@@ -30,6 +30,7 @@
 #include <kdatepicker.h>
 
 #include <QPushButton>
+#include <QDate>
 
 namespace Calligra
 {
