From c1adc0a7559340213d754db950fd68bfe9e5a651 Mon Sep 17 00:00:00 2001
From: Martin Whitaker <foss@martin-whitaker.me.uk>
Date: Sun, 15 Mar 2020 13:14:34 +0000
Subject: [PATCH] Fix build with poppler 0.86.0.

--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx.orig	2020-03-11 16:18:35 UTC
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx
@@ -563,7 +563,9 @@ void PDFOutDev::processLink(Link* link, Catalog*)
     if (!(pAction && pAction->getKind() == actionURI))
         return;
 
-#if POPPLER_CHECK_VERSION(0, 72, 0)
+#if POPPLER_CHECK_VERSION(0, 86, 0)
+    const char* pURI = static_cast<LinkURI*>(pAction)->getURI().c_str();
+#elif POPPLER_CHECK_VERSION(0, 72, 0)
     const char* pURI = static_cast<LinkURI*>(pAction)->getURI()->c_str();
 #else
     const char* pURI = static_cast<LinkURI*>(pAction)->getURI()->getCString();
