
$FreeBSD$

--- amarok/src/scancontroller.h.orig
+++ amarok/src/scancontroller.h
@@ -99,7 +99,7 @@
         void customEvent( QCustomEvent* );
 
         // Member variables:
-        static const uint MAX_RESTARTS = 2;
+        static const uint MAX_RESTARTS = 20;
 
         KProcIO* m_scanner;
         QStringList m_folders;
