--- base/include/eventdata.h.orig	Thu Feb  6 02:52:52 2003
+++ base/include/eventdata.h	Sat Sep 13 02:36:12 2003
@@ -241,7 +241,7 @@
 
       m_childEvents = new std::vector <Event *>(other.m_childEvents->size());
 
-      copy(other.m_childEvents->begin(), other.m_childEvents->end(),
+      std::copy(other.m_childEvents->begin(), other.m_childEvents->end(),
            m_childEvents->begin());
    }
 
