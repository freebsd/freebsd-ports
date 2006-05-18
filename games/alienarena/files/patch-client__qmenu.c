--- ./client/qmenu.c.orig	Tue May 16 15:20:10 2006
+++ ./client/qmenu.c	Tue May 16 15:20:10 2006
@@ -25,7 +25,8 @@
 
 static void	 Action_DoEnter( menuaction_s *a );
 static void	 Action_Draw( menuaction_s *a );
-static void  Menu_DrawStatusBar( const char *string );
+static void	 Menu_DrawStatusBar( const char *string );
+void		 Menu_DrawString( int x, int y, const char *string );
 static void	 Menulist_DoEnter( menulist_s *l );
 static void	 MenuList_Draw( menulist_s *l );
 static void	 Separator_Draw( menuseparator_s *s );
