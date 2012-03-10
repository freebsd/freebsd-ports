diff -urNad dialog.c dialog.c
--- dialog.c	1995-06-20 00:15:13.000000000 +0200
+++ dialog.c	2008-05-16 17:31:45.000000000 +0200
@@ -130,8 +130,8 @@
     Cardinal	 	i;
 
     textblock.firstPos = 0;
-    textblock.length   = 0;
-    textblock.ptr      = "";
+    textblock.length   = 1;
+    textblock.ptr      = " ";
 
     pos = XawTextGetInsertionPoint(w); 
     if (pos <= StartPos)
@@ -142,6 +142,30 @@
     XawTextSetInsertionPoint(w, i);
 }
 
+/*  Erases the preceding word.
+ *  Simulates the action of the WERASE character (ctrl-W).
+ */
+/* ARGSUSED */
+void DeleteChar(w, event, params, num_params)
+    Widget w;
+    XEvent *event;
+    String *params;
+    Cardinal *num_params;
+{
+    XawTextBlock    	textblock;
+    XawTextPosition	pos;
+
+    textblock.firstPos = 0;
+    textblock.length   = 1;
+    textblock.ptr      = " ";
+
+    pos = XawTextGetInsertionPoint(w); 
+    if (pos > StartPos) {
+    	XawTextReplace(w, pos-1, pos, &textblock);
+    	XawTextSetInsertionPoint(w, pos-1);
+    }
+}
+
 
 /*  Deletes the entire current input line.
  *  simulates the action of the KILL character (ctrl-U).
@@ -159,8 +183,8 @@
     char		*s;
 
     textblock.firstPos = 0;
-    textblock.length   = 0;
-    textblock.ptr      = "";
+    textblock.length   = 1;
+    textblock.ptr      = " ";
 
     pos = XawTextGetInsertionPoint(w); 
     if (w == dialogWindow) {
@@ -307,6 +331,7 @@
 	{"SigQuit", 	(XtActionProc) SigQuit},
 	{"InsertSpace", (XtActionProc) InsertSpace},
 	{"Dispatch", 	(XtActionProc) Dispatch},
+	{"DeleteChar", 	(XtActionProc) DeleteChar},
         {NULL, NULL}
     };
 
@@ -316,10 +341,10 @@
  	Ctrl<Key>|:	SigQuit()\n\
  	Ctrl<Key>W:	DeleteWord()\n\
  	Ctrl<Key>U:	DeleteLine()\n\
- 	Ctrl<Key>H:	InsertSpace() delete-previous-character()\n\
- 	<Key>Delete:	InsertSpace() delete-previous-character()\n\
- 	<Key>BackSpace:	InsertSpace() delete-previous-character()\n\
- 	<Key>Return:	newline() Dispatch()\n\
+ 	Ctrl<Key>H:	DeleteChar()\n\
+ 	<Key>Delete:	DeleteChar()\n\
+ 	<Key>BackSpace:	DeleteChar()\n\
+ 	<Key>Return:	newline()Dispatch()\n\
     ";
 
     n = 0;
