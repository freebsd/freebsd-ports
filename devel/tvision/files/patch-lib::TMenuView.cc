--- lib/TMenuView.cc.old	Fri Sep 28 15:40:42 2001
+++ lib/TMenuView.cc	Fri Sep 28 15:41:40 2001
@@ -470,7 +470,7 @@
             if( p->command == 0 )
                 {
                 TMenuItem *T;
-                if( (T = findHotKey( p->subMenu->items, keyCode )) != 0 )
+                if( p->subMenu != 0 && (T = findHotKey( p->subMenu->items, keyCode )) != 0 )
                     return T;
                 }
             else if( !p->disabled &&
