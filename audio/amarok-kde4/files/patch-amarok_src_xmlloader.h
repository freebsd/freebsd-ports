
$FreeBSD$

--- amarok/src/xmlloader.h.orig
+++ amarok/src/xmlloader.h
@@ -173,6 +173,7 @@
 
     public: //fucking moc, these should be private
         class ThreadedLoader;
+	friend class ThreadedLoader;
         class SimpleLoader;
 };
 
