--- gok/gok-keyboard.c.orig	Fri Nov  5 16:18:02 2004
+++ gok/gok-keyboard.c	Fri Nov  5 16:18:49 2004
@@ -2519,8 +2519,9 @@
 			else if ((pKeyboard->search_type == GOK_SPY_SEARCH_ACTIONABLE) && !did_actionkeys) 
 			{
 				gint action_count, i;
+				AccessibleAction *action;
 				did_actionkeys = TRUE;
-				AccessibleAction *action = 
+				action = 
 					Accessible_getAction (pNodeAccessible->paccessible);
 				if (!action) 
 					break;
