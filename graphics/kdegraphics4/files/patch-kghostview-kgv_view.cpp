--- kghostview/kgv_view.cpp	5 Feb 2004 19:40:01 -0000	1.172.2.2
+++ kghostview/kgv_view.cpp	15 Mar 2004 10:29:55 -0000
@@ -73,8 +73,6 @@
     }
 }
 
-K_EXPORT_COMPONENT_FACTORY( libkghostviewpart, KGVFactory )
-
 KGVPart::KGVPart( QWidget* parentWidget, const char*,
                   QObject* parent, const char* name,
                   const QStringList &args ) :
@@ -956,7 +954,7 @@
 	m_job->kill(true);
 	m_job = 0;
     }
-        
+
     _mimetype = mimetype;
 
     m_bFinished = true;
Index: kghostview/part_init.cpp
