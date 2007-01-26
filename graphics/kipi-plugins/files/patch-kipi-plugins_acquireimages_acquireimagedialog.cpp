--- kipi-plugins/acquireimages/acquireimagedialog.cpp.orig	Fri Jan 26 09:24:31 2007
+++ kipi-plugins/acquireimages/acquireimagedialog.cpp	Fri Jan 26 09:25:12 2007
@@ -120,7 +120,7 @@
     // About data and help button.
 
     m_about = new KIPIPlugins::KPAboutData(I18N_NOOP("Acquire images"),
-                                           NULL,
+                                           (char*) NULL,
                                            KAboutData::License_GPL,
                                            I18N_NOOP("A Kipi plugin to acquire images"),
                                            "(c) 2003-2004, Gilles Caulier");
