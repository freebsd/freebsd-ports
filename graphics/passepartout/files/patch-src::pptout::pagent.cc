--- src/pptout/document/pagent.cc.orig	Thu Dec  4 10:24:15 2003
+++ src/pptout/document/pagent.cc	Thu Dec  4 10:25:23 2003
@@ -77,8 +77,8 @@
       new_w(w), new_h(h), 
       old_w(pagent.get_width()), old_h(pagent.get_height())
     {}
-    void undo() const {pagent.set_size(new_w, new_h, false);}
-    void redo() const {pagent.set_size(old_w, old_h, false);}
+    void undo() const {pagent.set_size(new_w, new_h);}
+    void redo() const {pagent.set_size(old_w, old_h);}
   private:
     Pagent &pagent;
     float new_w, new_h, old_w, old_h;
@@ -104,7 +104,7 @@
       Action(locked ? "Lock" : "Unlock"),
       pagent(_pagent)
     {}
-    void undo() const {pagent.set_lock(!pagent.get_lock(), false);}
+    void undo() const {pagent.set_lock(!pagent.get_lock());}
     void redo() const {undo();}
   private:
     Pagent &pagent;
@@ -131,7 +131,7 @@
       pagent(_pagent)
     {}
     void undo() const 
-    {pagent.set_flow_around(!pagent.get_flow_around(), false);}
+    {pagent.set_flow_around(!pagent.get_flow_around());}
     void redo() const {undo();}
   private:
     Pagent &pagent;
@@ -155,8 +155,8 @@
       pagent(_pagent), 
       old_margin(pagent.get_obstacle_margin()), new_margin(margin)
     {}
-    void undo() const {pagent.set_obstacle_margin(old_margin, false);}
-    void redo() const {pagent.set_obstacle_margin(new_margin, false);}
+    void undo() const {pagent.set_obstacle_margin(old_margin);}
+    void redo() const {pagent.set_obstacle_margin(new_margin);}
   private:
     Pagent &pagent;
     float old_margin, new_margin;
@@ -181,8 +181,8 @@
       Action("Rename"),
       pagent(_pagent), old_name(pagent.get_name()), new_name(name)
     {}
-    void undo() const {pagent.set_name(old_name, false);}
-    void redo() const {pagent.set_name(new_name, false);}
+    void undo() const {pagent.set_name(old_name);}
+    void redo() const {pagent.set_name(new_name);}
   private:
     Pagent &pagent;
     std::string old_name, new_name;
