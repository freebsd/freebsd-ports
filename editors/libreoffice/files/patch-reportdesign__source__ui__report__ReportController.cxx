--- ./reportdesign/source/ui/report/ReportController.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./reportdesign/source/ui/report/ReportController.cxx	2012-07-18 15:01:02.000000000 -0400
@@ -325,7 +325,7 @@
 
     m_sMode =  ::rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("normal"));
     DBG_CTOR( rpt_OReportController,NULL);
-    registerProperty(::rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("ZoomValue")),PROPERTY_ID_ZOOMVALUE,beans::PropertyAttribute::BOUND| beans::PropertyAttribute::TRANSIENT,&m_nZoomValue,::getCppuType(reinterpret_cast< sal_Int16*>(NULL)));
+    registerProperty(::rtl::OUString(RTL_CONSTASCII_USTRINGPARAM("ZoomValue")),PROPERTY_ID_ZOOMVALUE,beans::PropertyAttribute::BOUND| beans::PropertyAttribute::TRANSIENT,&m_nZoomValue,::getCppuType(static_cast< sal_Int16*>(0)));
 
 }
 // -----------------------------------------------------------------------------
