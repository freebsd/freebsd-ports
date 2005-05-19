--- src/Merge.cpp.orig	Thu May 19 00:21:53 2005
+++ src/Merge.cpp	Thu May 19 00:24:07 2005
@@ -106,7 +106,7 @@
       }
 
       MergeDialogImpl * dlg = new MergeDialogImpl(workBench, whatsThisIconSet,
-	    parent, QString(isDir ? "" : masqWs(p->m_filesList.join("\" \""))), 
+	    parent, QString(isDir ? QString("") : masqWs(p->m_filesList.join("\" \""))), 
 	    currentTagList,
 	    dir->topControlledDir()->relativeName());
       if (!isDir) {
@@ -183,7 +183,7 @@
    command += firstTag;
    if (!secondTag.isEmpty()) command += " -j " + secondTag;
 
-   QString files = m_filesList.isEmpty() ? "" : masqWs(m_filesList.join("\" \""));
+   QString files = m_filesList.isEmpty() ? QString("") : masqWs(m_filesList.join("\" \""));
    QString dir = m_dir->fullName();
    QString topModule = m_dir->topControlledDir()->relativeName();
    
