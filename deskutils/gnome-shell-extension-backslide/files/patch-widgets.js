Support gnome-shell 3.18
https://bitbucket.org/LukasKnuth/backslide/issues/64/extension-broken-in-gnome-318-here-is-a

--- backslide@codeisland.org/widgets.js.orig	2015-11-18 15:28:14.531127000 +0100
+++ backslide@codeisland.org/widgets.js	2015-11-18 15:30:59.671877000 +0100
@@ -482,11 +482,16 @@
     _init: function(value) {
         this.parent();
 
-        this._box = new St.Table({style_class: 'slider-item'});
+	//DOM 20151024
+        this._box = new St.Widget({style_class: 'slider-item',
+				   layout_manager: new Clutter.TableLayout(),
+				   reactive: true});
 
         this._slider = new Slider.Slider(value);
 
-        this._box.add(this._slider.actor, {row: 0, col: 2, x_expand: true});
+	//DOM 20151024
+        this._box.layout_manager.pack(this._slider.actor, 2, 0);
+
         this.actor.add(this._box, {span: -1, expand: true});
     },
 
