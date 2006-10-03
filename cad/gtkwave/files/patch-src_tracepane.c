--- src/tracepane.c.orig	Mon Oct  2 19:14:31 2006
+++ src/tracepane.c	Mon Oct  2 19:14:36 2006
@@ -43,7 +43,7 @@
 static int in_button_press = 0;
 static gfloat old_wvalue = -1.0;
 static TimeType prevtim = -1;
-static GdkPixmap *wavepixmap = NULL;
+GdkPixmap *wavepixmap = NULL;
 
 static const GdkModifierType bmask[4] = { 0, GDK_BUTTON1_MASK, 0, GDK_BUTTON3_MASK }; /* button 1, 3 press/rel encodings */
 static const GdkModifierType m_bmask[4] = { 0, GDK_BUTTON1_MOTION_MASK, 0, GDK_BUTTON3_MOTION_MASK }; /* button 1, 3 motion encodings */
