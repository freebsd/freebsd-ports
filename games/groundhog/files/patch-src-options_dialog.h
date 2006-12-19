Index: files/patch-src-element.h
===================================================================
RCS file: files/patch-src-element.h
diff -N files/patch-src-element.h
--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ files/patch-src-element.h	16 Dec 2006 13:15:54 -0000
@@ -0,0 +1,10 @@
+--- src/element.h.orig	Sat Dec 16 18:57:18 2006
++++ src/element.h	Sat Dec 16 18:57:31 2006
+@@ -24,6 +24,7 @@
+ class Element {
+ public:
+   Element() {}
++  virtual ~Element() {}
+   virtual void PutBall(Ball* ball);
+   virtual void MoveBall(Ball* ball) = 0;
+   virtual void ConnectLeft(Element* element) = 0;
Index: files/patch-src-options_dialog.h
===================================================================
RCS file: files/patch-src-options_dialog.h
diff -N files/patch-src-options_dialog.h
--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ files/patch-src-options_dialog.h	16 Dec 2006 13:16:14 -0000
@@ -0,0 +1,11 @@
+--- src/options_dialog.h.orig	Sat Dec 16 18:57:43 2006
++++ src/options_dialog.h	Sat Dec 16 18:57:50 2006
+@@ -28,7 +28,7 @@
+    Game*	_game;
+    GtkWidget*	_tooltips;
+ 
+-   void OptionsDialog::OnOk();
++   void OnOk();
+ public:
+    OptionsDialog(Game* game);
+ };
