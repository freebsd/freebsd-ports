--- glui.h.orig	Sat Oct  5 12:33:27 2002
+++ glui.h	Sat Oct  5 12:34:09 2002
@@ -295,8 +295,8 @@
     parent_node= child_head = child_tail = next_sibling = prev_sibling = NULL;
   }; 
 
-  friend GLUI_Rollout;
-  friend GLUI_Main;
+  friend class GLUI_Rollout;
+  friend class GLUI_Main;
 };
 
 
@@ -559,11 +559,11 @@
 
   /********** Friend classes *************/
 
-  friend GLUI_Control;
-  friend GLUI_Rotation;
-  friend GLUI_Translation;
-  friend GLUI;
-  friend GLUI_Master_Object;
+  friend class GLUI_Control;
+  friend class GLUI_Rotation;
+  friend class GLUI_Translation;
+  friend class GLUI;
+  friend class GLUI_Master_Object;
 
 
   /********** Misc functions *************/
