diff --git src/Gui/SoFCCSysDragger.cpp src/Gui/SoFCCSysDragger.cpp
index 0c47d086a7..cf07f7f010 100644
--- src/Gui/SoFCCSysDragger.cpp
+++ src/Gui/SoFCCSysDragger.cpp
@@ -90,7 +90,7 @@ TDragger::TDragger()
 {
     SO_KIT_CONSTRUCTOR(TDragger);
 
-#if defined(Q_OS_MAC)
+#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD)
     this->ref();
 #endif
 
@@ -379,7 +379,7 @@ RDragger::RDragger()
 {
     SO_KIT_CONSTRUCTOR(RDragger);
 
-#if defined(Q_OS_MAC)
+#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD)
     this->ref();
 #endif
 
@@ -674,6 +674,10 @@ SoFCCSysDragger::SoFCCSysDragger()
 {
     SO_KIT_CONSTRUCTOR(SoFCCSysDragger);
 
+#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD)
+    this->ref();
+#endif
+
     SO_KIT_ADD_CATALOG_ENTRY(annotation, SoAnnotation, TRUE, geomSeparator, "", TRUE);
     SO_KIT_ADD_CATALOG_ENTRY(scaleNode, SoScale, TRUE, annotation, "", TRUE);
 
