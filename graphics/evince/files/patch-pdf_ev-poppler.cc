--- pdf/ev-poppler.cc.orig	Thu Apr  7 16:22:58 2005
+++ pdf/ev-poppler.cc	Thu Apr  7 16:23:46 2005
@@ -88,10 +88,10 @@
 							pdf_document_document_links_iface_init);
 				 G_IMPLEMENT_INTERFACE (EV_TYPE_DOCUMENT_FIND,
 							pdf_document_find_iface_init);
-#if 0
+/* #if 0
 				 G_IMPLEMENT_INTERFACE (EV_TYPE_PS_EXPORTER,
 							pdf_document_ps_exporter_iface_init);
-#endif
+#endif */
 			 });
 
 
