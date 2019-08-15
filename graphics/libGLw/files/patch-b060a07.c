diff --git a/GLwDrawA.h b/GLwDrawA.h
index b9711c216bc458f7ec2d2055495045efef8903f0..316a70d5d2061af67d8307c74706208907c3ac6a 100644
--- GLwDrawA.h
+++ GLwDrawA.h
@@ -131,12 +131,18 @@
 #define GLwNaccumAlphaSize	"accumAlphaSize"
 #define GLwCAccumAlphaSize	"AccumAlphaSize"
 
+#if (defined(__GNUC__) && __GNUC__ >= 4) || (defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590))
+#  define GLAPIVAR extern __attribute__((visibility("default")))
+#else
+#  define GLAPIVAR extern
+#endif
+
 #ifdef __GLX_MOTIF
 
 typedef struct _GLwMDrawingAreaClassRec	*GLwMDrawingAreaWidgetClass;
 typedef struct _GLwMDrawingAreaRec	*GLwMDrawingAreaWidget;
 
-GLAPI WidgetClass glwMDrawingAreaWidgetClass;
+GLAPIVAR WidgetClass glwMDrawingAreaWidgetClass;
 
 
 #else 
@@ -144,7 +150,7 @@ GLAPI WidgetClass glwMDrawingAreaWidgetClass;
 typedef struct _GLwDrawingAreaClassRec	*GLwDrawingAreaWidgetClass;
 typedef struct _GLwDrawingAreaRec	*GLwDrawingAreaWidget;
 
-GLAPI WidgetClass glwDrawingAreaWidgetClass;
+GLAPIVAR WidgetClass glwDrawingAreaWidgetClass;
 
 
 #endif
diff --git a/GLwDrawAP.h b/GLwDrawAP.h
index 4ff21b426dd5912e007356160ef6fe5a41536c24..6d29849d4288f4affaa5ed3f5d5d5bc1668d4cd3 100644
--- GLwDrawAP.h
+++ GLwDrawAP.h
@@ -59,7 +59,7 @@ typedef struct _GLwMDrawingAreaClassRec {
   } GLwMDrawingAreaClassRec;
 
 
-GLAPI GLwMDrawingAreaClassRec glwMDrawingAreaClassRec;
+GLAPIVAR GLwMDrawingAreaClassRec glwMDrawingAreaClassRec;
 
 
 /* XT */
@@ -70,7 +70,7 @@ typedef struct _GLwDrawingAreaClassRec {
   GLwDrawingAreaClassPart     glwDrawingArea_class;
   } GLwDrawingAreaClassRec;
 
-GLAPI GLwDrawingAreaClassRec glwDrawingAreaClassRec;
+GLAPIVAR GLwDrawingAreaClassRec glwDrawingAreaClassRec;
 
 
 #endif 
