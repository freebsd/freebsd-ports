
--- src/main.c      11 Mar 2010 04:03:58 -0000      1.792
+++ src/main.c      7 May 2010 16:23:16 -0000       1.793
@@ -9018,6 +9018,12 @@
             "create_appshell Menu Popup",
             al,
             ac);
+#if XmVersion >= 2000
+    XtVaSetValues(right_menu_popup, XmNpopupEnabled, XmPOPUP_DISABLED, NULL);
+    XtUngrabButton(da, AnyButton, AnyModifier);
+#else
+    XtVaSetValues(right_menu_popup, XmNpopupEnabled, False, NULL);
+#endif
     //XtVaSetValues(right_menu_popup, XmNwhichButton, 3, NULL);
 
     ac = 0;



