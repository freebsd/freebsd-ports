--- GUI_menu.h	Tue Apr 17 00:16:46 2007
+++ GUI_menu.h	Tue Apr 17 00:17:29 2007
@@ -39,9 +39,9 @@
   virtual void AddSubitem(GUI_Menuitem *newitem);
   virtual GUI_Menuitem* GetSubItem(int Aid);
 
-  GUI_status GUI_Submenu:: MouseDown(int x, int y, int button);
-  GUI_status GUI_Submenu::MouseUp(int x,int y,int button);
-  GUI_status GUI_Submenu::MouseMotion(int x,int y,Uint8 state);
+  GUI_status MouseDown(int x, int y, int button);
+  GUI_status MouseUp(int x,int y,int button);
+  GUI_status MouseMotion(int x,int y,Uint8 state);
 
   inline virtual int GetSubmenuId()
     {return submenuid;}
