--- inputaudiofile.cpp.orig	2016-01-29 18:07:49 UTC
+++ inputaudiofile.cpp
@@ -135,8 +135,8 @@ bool InputAudioFile::load()
     {
         qWarning("------------------------------------");
         qWarning() << "Test audio command:" << (shntool + " " + args.join(" "));
-        qWarning() << "shntool info waitForFinished faild";
-        qWarning(proc.readAllStandardError());
+        qWarning() << "shntool info waitForFinished failed";
+        qWarning() << proc.readAllStandardError();
         qWarning("------------------------------------");
         return false;
     }
@@ -147,7 +147,7 @@ bool InputAudioFile::load()
         qWarning("------------------------------------");
         qWarning() << "Test audio command:" << (shntool + " " + args.join(" "));
         qWarning() << "shntool info nonzero exit code:" << proc.exitCode();
-        qWarning(proc.readAllStandardError());
+        qWarning() << proc.readAllStandardError();
         qWarning("------------------------------------");
         mErrorString = QObject::tr("File <b>%1</b> is not a supported audio file. <br>"
                                    "<br>Verify that all required programs are installed and in your preferences.").arg(mFileName);
