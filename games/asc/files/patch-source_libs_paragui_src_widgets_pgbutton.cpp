--- source/libs/paragui/src/widgets/pgbutton.cpp.orig	2015-04-11 02:43:58.716405000 +0300
+++ source/libs/paragui/src/widgets/pgbutton.cpp	2015-04-11 02:44:38.509415000 +0300
@@ -101,32 +101,33 @@
 	t->GetColor(widgettype, objectname, PG_PropStr::textcolor, fontcolor);
 	SetFontColor(fontcolor);
 
+	printf("%d\n", GetID());
 	switch (GetID()) {
-		case OK:
+		case (int)OK:
 			SetIcon(t->FindSurface(widgettype, objectname, "ok_icon"));
 			break;
 
-		case YES:
+		case (int)YES:
 			SetIcon(t->FindSurface(widgettype, objectname, "yes_icon"));
 			break;
 
-		case NO:
+		case (int)NO:
 			SetIcon(t->FindSurface(widgettype, objectname, "no_icon"));
 			break;
 
-		case APPLY:
+		case (int)APPLY:
 			SetIcon(t->FindSurface(widgettype, objectname, "apply_icon"));
 			break;
 
-		case CANCEL:
+		case (int)CANCEL:
 			SetIcon(t->FindSurface(widgettype, objectname, "cancel_icon"));
 			break;
 
-		case CLOSE:
+		case (int)CLOSE:
 			SetIcon(t->FindSurface(widgettype, objectname, "close_icon"));
 			break;
 
-		case HELP:
+		case (int)HELP:
 			SetIcon(t->FindSurface(widgettype, objectname, "help_icon"));
 			break;
 
