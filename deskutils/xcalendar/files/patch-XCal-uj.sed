--- XCal-uj.sed.orig	Sun Oct  1 14:31:06 1995
+++ XCal-uj.sed	Sat Nov 22 00:58:44 2003
@@ -3,7 +3,9 @@
 *showGrip:		False
 *calendar*internalBorderWidth: 0
 *input:		True
-*resize: False
+*controls*resize: False
+*bcontrols*resize: False
+*daybuttons*resize: False
 *resizable: True
 *title: XCalendar v.4.0
 *dayEditor.title: Day Editor
@@ -21,8 +23,8 @@
 *succ*Label: 来月
 *prevday*Label: 昨日
 *succday*Label: 明日
-*helpButton*label: 助け
-*quitButton*label: 終り
+*helpButton*Label: 助け
+*quitButton*Label: 終り
 
 *daynames.SUN.label: \ 日
 *daynames.MON.label: \ 月
@@ -32,20 +34,12 @@
 *daynames.FRI.label: \ 金
 *daynames.SAT.label: \ 土
 
-*prev*labelString: 先月
-*succ*labelString: 来月
-*prevday*labelString: 昨日
-*succday*labelString: 明日
-*helpButton*labelString: 助け
-*quitButton*labelString: 終り
-
-*daynames.SUN.labelString: \ 日
-*daynames.MON.labelString: \ 月
-*daynames.TUE.labelString: \ 火
-*daynames.WED.labelString: \ 水
-*daynames.THU.labelString: \ 木
-*daynames.FRI.labelString: \ 金
-*daynames.SAT.labelString: \ 土
+*monthnames:	1/2/3/4/5/6/7/8/9/10/11/12
+*monthnms:	1/2/3/4/5/6/7/8/9/10/11/12
+*daynames:	日曜日/月曜日/火曜日/水曜日/木曜日/金曜日/土曜日
+*daynms:	日/月/火/水/木/金/土                            
+*date:		%M月%d日(%W)
+
 
 #ifdef COLOR
 ! colors
@@ -70,11 +64,12 @@
 *editorControls*Background: lightgray
 *editorControls*Command.Background: slategray
 *editorControls*Command.Foreground: White
+*editorControls*XmPushButton.Background: slategray
+*editorControls*XmPushButton.Foreground: White
 #endif
 
 *setMarkBackground: True
 *markOnStartup: True
-!
 *markCurrent: True
 *currentForeground: Blue
 *markHoliday: True
@@ -88,57 +83,38 @@
 *prev*vertDistance: 0
 *succ*vertDistance: 0
 
-*controls*date*fontSet:		8x13bold
-*daynames*fontSet:			-*--14-*
-*dayEditor*editorTitle*fontSet:	8x13bold
-*helpWindow*editorTitle*fontSet:	8x13bold
+*controls*date*fontSet:		8x13bold, -*-r-*--14-*
+*daynames*fontSet:			-*-r-*--14-*
+*dayEditor*editorTitle*fontSet:	8x13bold, -*-r-*--14-*
+*helpWindow*editorTitle*fontSet:	8x13bold, -*-r-*--14-*
 
 *helpButton*vertDistance: 5
 *quitButton*vertDistance: 5
 *editorTitle*vertDistance: 5
-*cdate*vertDistance: 0
+*cdate*vertDistance: 5
 
 *editorControls*doneButton*label: 終り
 *editorControls*saveButton*label: 保存
 *editorControls*clearEntry*label: 消えてなくなれ
-*editorControls*doneButton*labelString: 終り
-*editorControls*saveButton*labelString: 保存
-*editorControls*clearEntry*labelString: 消えてなくなれ
+*doneButton*labelString: 終り
+*saveButton*labelString: 保存
+*clearEntry*labelString: 消えてなくなれ
 
 *dayEditor*geometry: 300x150
 *helpWindow*geometry: 600x350
 
-*doneButton*Label: done
-*editorTitle*Label: Help
-*saveButton*Label: save
-
-*bcontrols*borderWidth: 0
-*prev*highlightThickness: 0
-*succ*highlightThickness: 0
-
-*prevday*highlightThickness: 0
-*succday*highlightThickness: 0
-*daybuttons*borderWidth: 0
+*dayEditor*fontSet:			-*-r-*--14-*
+*controls*fontSet:			-*-r-*--14-*
+*bcontrols*fontSet:			-*-r-*--14-*
+*editorControls*fontSet:		-*-r-*--14-*
+*fontSet: 				-*-r-*--14-*
 
-*Scrollbar.borderWidth: 1
-*editor.scrollVertical: whenNeeded
-! *scrollHorizontal: False
-! *helpWindow*scrollHorizontal: True
-*holiday*cursorPositionVisible: False
-*holiday*displayCaret: False
-*helpWindow*cursorPositionVisible: False
-*helpWindow*displayCaret: False
-
-
-*dayEditor*fontSet:			-*--14-*
-*controls*fontSet:			-*--14-*
-*bcontrols*fontSet:			-*--14-*
-*editorControls*fontSet:		-*--14-*
-*fontSet: 				-*--14-*
 !*preeditType: Root
 !*preeditType: OffTheSpot
 *preeditType: OverTheSpot
 
+*helpWindow*editorTitle*label: ヘルプ
+*helpWindow*editorTitle*labelString: ヘルプ
 *helpWindow*rows: 15
 *helpWindow*columns: 80
 *rows:7
@@ -149,11 +125,18 @@
 *helpWindow*Paned*editor.width: 600
 *helpWindow*Paned*editor.height: 350
 
+*bcontrols*borderWidth: 0
+*prev*highlightThickness: 0
+*succ*highlightThickness: 0
+
+*prevday*highlightThickness: 0
+*succday*highlightThickness: 0
+*daybuttons*borderWidth: 0
 
 *Scrollbar.borderWidth: 1
-*Text*scrollVertical: whenNeeded
-*scrollHorizontal: False
-*helpWindow*scrollHorizontal: True
+*Text*scrollVertical: always
+*scrollHorizontal: Never
+*helpWindow*scrollHorizontal: Always
 *holiday*cursorPositionVisible: False
 *holiday*displayCaret: False
 *helpWindow*cursorPositionVisible: False
