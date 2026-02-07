From 140b9cae66ba874bf0994eea71210baf417a136e Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Kondor=20D=C3=A1niel?= <kondor.dani@gmail.com>
Date: Sat, 22 Sep 2018 22:42:06 +0800
Subject: [PATCH] fixed recurring crash when trying to render 0x0 tray icon

---
 win.cc | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/win.cc b/win.cc
index da41b0e8..36746430 100644
--- win.cc
+++ win.cc
@@ -275,7 +275,7 @@ void Win::timeout() {
 }
 
 void Win::set_icon(RStroke stroke, bool invert) {
-	if (!icon)
+	if (!icon || icon->get_size() <= 0)
 		return;
 	icon->set(stroke->draw(icon->get_size(), 2.0, invert));
 	set_timeout(10000);
