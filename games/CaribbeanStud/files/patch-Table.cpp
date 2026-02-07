--- ./Table.cpp.orig	2013-10-29 15:12:13.000000000 -0200
+++ ./Table.cpp	2013-10-29 15:12:13.000000000 -0200
@@ -306,7 +306,7 @@
 	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_POSITION); ac++;
 	XtSetArg(al[ac], XmNbottomPosition, 30); ac++;
    XtSetArg(al[ac], XmNalignment, XmALIGNMENT_CENTER); ac++;
-   for(j=0; j < rv.players; j++) 
+   for(int j=0; j < rv.players; j++) 
    { 
 		XtSetArg(al[ac], XmNtopWidget, YouHaveLabel[j]);
       XtSetArg(al[ac+1], XmNleftPosition, j*100/rv.players); 
@@ -324,7 +324,7 @@
    XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_POSITION); ac++;
    XtSetArg(al[ac], XmNbottomPosition, 40); ac++;
    XtSetArg(al[ac], XmNalignment, XmALIGNMENT_CENTER); ac++;
-   for(j=0; j < rv.players; j++)
+   for(int j=0; j < rv.players; j++)
    {
       XtSetArg(al[ac], XmNtopWidget, YouHaveLabelValue[j]);
       XtSetArg(al[ac+1], XmNleftPosition, j*100/rv.players);
@@ -465,7 +465,7 @@
    XtManageChild(HelpRulesScrolledText);
 
 
-   for(j=0; j< rv.players; j++)
+   for(int j=0; j< rv.players; j++)
 	{
 	  ac = 0;
 	  children[ac++] = YouHaveLabel[j];
@@ -534,7 +534,7 @@
    Arg args[5];
 
    i = 0;
-   s = XmStringCreate(str, XmSTRING_DEFAULT_CHARSET);
+   s = XmStringCreate((char*)str, XmSTRING_DEFAULT_CHARSET);
    XtSetArg(args[i], XmNmessageString, s);   i++;
    XtSetValues(ExceptionDialog, args, i);
    XmStringFree(s);
@@ -586,7 +586,7 @@
   try{
 #ifdef DEBUG
    cout << "Calling DealerDrawingAreaCB" << endl;
-#endif DEBUG
+#endif // DEBUG
    if (call_data->window) {
      XEvent event;
      Table * table = (Table*) client_data;
@@ -615,7 +615,7 @@
   try{  
 #ifdef DEBUG
    cout << "Calling PlayerDrawingAreaCB" << endl;
-#endif DEBUG
+#endif // DEBUG
 
    if (call_data->window) {
      XEvent event; 
@@ -648,7 +648,7 @@
 {
 #ifdef DEBUG
    cout << "Calling AnteScrollCB" << endl;
-#endif DEBUG
+#endif // DEBUG
    int i;
    char str[80];
    Arg  args[5];
@@ -686,7 +686,7 @@
 {
 #ifdef DEBUG
    cout << "Calling DealCB" << endl;
-#endif DEBUG
+#endif // DEBUG
    Arg  args[5];
    char str[80];
 	XmScaleCallbackStruct  data;
@@ -763,7 +763,7 @@
   try{
 #ifdef DEBUG
    cout << "Calling BetCB" << endl;
-#endif DEBUG
+#endif // DEBUG
    char str[80];
    Arg  args[5];
 
@@ -792,7 +792,7 @@
   try{
 #ifdef DEBUG
    cout << "Calling FoldCB" << endl;
-#endif DEBUG
+#endif // DEBUG
 
    char str[80];
    Arg  args[5];
@@ -823,7 +823,7 @@
   try{
 #ifdef DEBUG
    cout << "Calling Table::PayTime" << endl;
-#endif DEBUG
+#endif // DEBUG
 
    char str[80];
    Arg  args[5];
