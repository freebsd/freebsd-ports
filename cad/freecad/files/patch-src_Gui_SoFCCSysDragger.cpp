--- src/Gui/SoFCCSysDragger.cpp.orig	2024-03-20 18:17:18 UTC
+++ src/Gui/SoFCCSysDragger.cpp
@@ -94,7 +94,7 @@ TDragger::TDragger()
 {
     SO_KIT_CONSTRUCTOR(TDragger);
 
-#if defined(Q_OS_MAC)
+#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD)
     this->ref();
 #endif
 
@@ -696,7 +696,7 @@ RDragger::RDragger()
 RDragger::RDragger()
 {
     SO_KIT_CONSTRUCTOR(RDragger);
-#if defined(Q_OS_MAC)
+#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD)
     this->ref();
 #endif
 
@@ -1005,6 +1005,10 @@ SoFCCSysDragger::SoFCCSysDragger()
     : axisScale(1.0f, 1.0f, 1.0f)
 {
     SO_KIT_CONSTRUCTOR(SoFCCSysDragger);
+
+#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD)
+    this->ref();
+#endif
 
     SO_KIT_ADD_CATALOG_ENTRY(annotation, SoAnnotation, TRUE, geomSeparator, "", TRUE);
     SO_KIT_ADD_CATALOG_ENTRY(scaleNode, SoScale, TRUE, annotation, "", TRUE);
