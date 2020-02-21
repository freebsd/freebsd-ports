commit e7a4ae3c9fa987d625b537573fd811a9cb5d2fb8
Author: Ingo Weyrich <heckflosse67@gmx.de>
Date:   Tue Feb 18 18:07:45 2020 +0100

    Fix segfault on close of RT when RT was started with a filename as argument

diff --git a/rtgui/rtwindow.cc b/rtgui/rtwindow.cc
index 8cfeb8ec0..fc315e1b7 100644
--- rtgui/rtwindow.cc.orig	2020-02-04 06:39:52 UTC
+++ rtgui/rtwindow.cc
@@ -99,6 +99,8 @@ RTWindow::RTWindow ()
     , bpanel (nullptr)
     , splash (nullptr)
     , btn_fullscreen (nullptr)
+    , iFullscreen (nullptr)
+    , iFullscreen_exit (nullptr)
     , epanel (nullptr)
     , fpanel (nullptr)
 {
