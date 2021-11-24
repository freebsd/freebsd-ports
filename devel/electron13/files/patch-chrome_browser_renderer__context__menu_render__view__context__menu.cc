--- chrome/browser/renderer_context_menu/render_view_context_menu.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/renderer_context_menu/render_view_context_menu.cc
@@ -2148,7 +2148,7 @@ bool RenderViewContextMenu::IsCommandIdEnabled(int id)
     case IDC_CHECK_SPELLING_WHILE_TYPING:
       return prefs->GetBoolean(spellcheck::prefs::kSpellCheckEnable);
 
-#if !defined(OS_MAC) && defined(OS_POSIX)
+#if !defined(OS_MAC) && !defined(OS_BSD) && defined(OS_POSIX)
     // TODO(suzhe): this should not be enabled for password fields.
     case IDC_INPUT_METHODS_MENU:
       return true;
