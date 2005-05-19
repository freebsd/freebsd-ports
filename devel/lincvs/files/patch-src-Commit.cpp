--- src/Commit.cpp.orig	Thu May 19 00:31:24 2005
+++ src/Commit.cpp	Thu May 19 00:31:57 2005
@@ -188,7 +188,7 @@
       command += " -r " + rev;
    }
    
-   QString files = m_filesList.isEmpty() ? "" : masqWs(m_filesList.join("\" \""));
+   QString files = m_filesList.isEmpty() ? QString("") : masqWs(m_filesList.join("\" \""));
    QString dir = m_dir->fullName();
    QString topModule = m_dir->topControlledDir()->relativeName();
    
