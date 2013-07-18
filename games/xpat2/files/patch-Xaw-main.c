--- Xaw-main.c.orig
+++ Xaw-main.c
@@ -323,6 +323,7 @@
     Widget buttonpanel;
     Widget gamebutton, gamemenu, rulesbutton, rulesmenu;
     int i;
+    Arg args[1];
     struct button {
 	const char *name; void (*func)(void);
     } *bp;
@@ -403,6 +404,9 @@
     /* OK. Now do the pop-up shells */
     popup = XtCreatePopupShell("prompt", transientShellWidgetClass, toplevel, NULL, 0);
     dialog = XtCreateManagedWidget("dialog", dialogWidgetClass, popup, NULL, 0);
+    /* cludge to be improved when I know more Xaw -- AW */
+    XtSetArg(args[0], XtNlabel, (strlen(TXT_NEW_CONFIRM)>strlen(TXT_QUIT_CONFIRM))?TXT_NEW_CONFIRM:TXT_QUIT_CONFIRM);
+    XtSetValues(dialog, args, 1);
     XawDialogAddButton(dialog, "ok",     Ok,     (XtPointer)dialog);
     XawDialogAddButton(dialog, "cancel", Cancel, (XtPointer)dialog);
 
