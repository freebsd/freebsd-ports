
$FreeBSD$

--- ../../src/mptrace.c
+++ ../../src/mptrace.c
@@ -268,27 +268,27 @@
 static XtResource resources[] =
 {
     {"alloc", XmCColor, XmRPixel, sizeof(Pixel),
-     (Cardinal) &alcol, XmRString, (XtPointer) "black"},
+     (long) &alcol, XmRString, (XtPointer) "black"},
     {"base", "Base", XmRInt, sizeof(void *),
-     (Cardinal) &addrbase, XmRImmediate, (XtPointer) NULL},
+     (long) &addrbase, XmRImmediate, (XtPointer) NULL},
     {"delay", "Delay", XmRInt, sizeof(unsigned long),
-     (Cardinal) &delay, XmRImmediate, (XtPointer) 0},
+     (long) &delay, XmRImmediate, (XtPointer) 0},
     {"free", XmCColor, XmRPixel, sizeof(Pixel),
-     (Cardinal) &frcol, XmRString, (XtPointer) "white"},
+     (long) &frcol, XmRString, (XtPointer) "white"},
     {"height", XmCHeight, XmRShort, sizeof(Dimension),
-     (Cardinal) &height, XmRImmediate, (XtPointer) 512},
+     (long) &height, XmRImmediate, (XtPointer) 512},
     {"internal", XmCColor, XmRPixel, sizeof(Pixel),
-     (Cardinal) &incol, XmRString, (XtPointer) "red"},
+     (long) &incol, XmRString, (XtPointer) "red"},
     {"space", "Space", XmRInt, sizeof(unsigned long),
-     (Cardinal) &addrspace, XmRImmediate, (XtPointer) 4},
+     (long) &addrspace, XmRImmediate, (XtPointer) 4},
     {"unalloc", XmCColor, XmRPixel, sizeof(Pixel),
-     (Cardinal) &uncol, XmRString, (XtPointer) "blue"},
+     (long) &uncol, XmRString, (XtPointer) "blue"},
     {"view-height", XmCHeight, XmRShort, sizeof(Dimension),
-     (Cardinal) &vheight, XmRImmediate, (XtPointer) 256},
+     (long) &vheight, XmRImmediate, (XtPointer) 256},
     {"view-width", XmCWidth, XmRShort, sizeof(Dimension),
-     (Cardinal) &vwidth, XmRImmediate, (XtPointer) 256},
+     (long) &vwidth, XmRImmediate, (XtPointer) 256},
     {"width", XmCWidth, XmRShort, sizeof(Dimension),
-     (Cardinal) &width, XmRImmediate, (XtPointer) 512}
+     (long) &width, XmRImmediate, (XtPointer) 512}
 };
 
 
