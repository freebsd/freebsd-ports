--- src/LogDialogImpl.cpp.orig	Fri Aug 20 10:57:57 2004
+++ src/LogDialogImpl.cpp	Fri Aug 20 11:00:34 2004
@@ -806,7 +806,8 @@
        break;
      }
      case EDIT_REVISION_CMD: {
-       setPermission(QFile(m_tmpDiffFileNameA),READABLE);//don't think you could change the file
+       QFile tmpFile(m_tmpDiffFileNameA);
+       setPermission(tmpFile, READABLE);//don't think you could change the file
        emit editFile(m_tmpDiffFileNameA);
        break;
      }
