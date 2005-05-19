--- src/Add.cpp.orig	Thu May 19 00:34:26 2005
+++ src/Add.cpp	Thu May 19 00:34:52 2005
@@ -224,7 +224,7 @@
       }
    }
 
-   QString files = m_filesList.isEmpty() ? "" : masqWs(m_filesList.join("\" \""));
+   QString files = m_filesList.isEmpty() ? QString("") : masqWs(m_filesList.join("\" \""));
    QString dir = m_dir->fullName();
    QString topModule = m_dir->topControlledDir()->relativeName();
    
