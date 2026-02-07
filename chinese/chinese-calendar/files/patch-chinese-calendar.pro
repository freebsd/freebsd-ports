--- chinese-calendar.pro.orig	2022-11-20 19:00:38 UTC
+++ chinese-calendar.pro
@@ -13,20 +13,20 @@ OBJECTS_DIR += build/
 #}
 
 inst.files += src/KylinLunar.db
-inst.path = /usr/share/chinese-calendar/db
+inst.path = $$PREFIX/share/chinese-calendar/db
 inst1.files += data/img/chinesecalendar-64.png
-inst1.path = /usr/share/pixmaps
+inst1.path = $$PREFIX/share/pixmaps
 inst2.files += data/chinese-calendar.desktop
-inst2.path = /usr/share/applications
+inst2.path = $$PREFIX/share/applications
 inst3.files += data/chinese-calendar-autostart.desktop
 inst3.path = /etc/xdg/autostart
 inst4.files += data/chinese-calendar-autostart
-inst4.path = /usr/bin
+inst4.path = $$PREFIX/bin
 default_skin.files += data/skin/default/chinesecalendarBGyellow.png \
     data/skin/default/no.png \
     data/skin/default/note.png \
     data/skin/default/ok.png
-default_skin.path = /usr/share/chinese-calendar/skin/default
+default_skin.path = $$PREFIX/share/chinese-calendar/skin/default
 blue_skin.files += data/skin/blue/yijibg.png \
     data/skin/blue/no.png \
     data/skin/blue/note.png \
@@ -40,7 +40,7 @@ blue_skin.files += data/skin/blue/yijibg.png \
         data/skin/blue/corner2.png \
         data/skin/blue/corner3.png \
         data/skin/blue/corner4.png
-blue_skin.path = /usr/share/chinese-calendar/skin/blue
+blue_skin.path = $$PREFIX/share/chinese-calendar/skin/blue
 black_skin.files += data/skin/black/chinesecalendar.png \
     data/skin/black/no.png \
     data/skin/black/no-hover.png \
@@ -50,16 +50,16 @@ black_skin.files += data/skin/black/chinesecalendar.pn
     data/skin/black/arrow-left.png \
     data/skin/black/arrow-right.png \
     data/skin/black/arrow-down.png
-black_skin.path = /usr/share/chinese-calendar/skin/black
+black_skin.path = $$PREFIX/share/chinese-calendar/skin/black
 qss.files += data/skin/default-skin.qss \
     data/skin/blue-skin.qss \
     data/skin/black.qss
-qss.path = /usr/share/chinese-calendar/skin
+qss.path = $$PREFIX/share/chinese-calendar/skin
 readme.files += data/skin/README.md
-readme.path = /usr/share/chinese-calendar/skin
+readme.path = $$PREFIX/share/chinese-calendar/skin
 
 target.source += $$TARGET
-target.path = /usr/bin
+target.path = $$PREFIX/bin
 INSTALLS += inst \
     inst1 \
     inst2 \
