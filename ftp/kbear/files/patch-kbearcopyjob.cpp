--- kbear/lib/jobclasses/kbearcopyjob.cpp.orig	Mon Feb  9 13:13:28 2004
+++ kbear/lib/jobclasses/kbearcopyjob.cpp	Mon Feb  9 13:13:56 2004
@@ -1080,11 +1080,7 @@
         } else if (m_mode == Move) // Moving a file
         {
             KBearFileCopyJob * moveJob = KBearFileCopyJob::file_move( m_destID, m_sourceID, (*it).uSource, (*it).uDest, (*it).permissions, bOverwrite, false, false/*no GUI*/ );
- #if KDE_VERSION_MINOR < 2
             moveJob->setSourceSize( (*it).size );
-  #else
-           moveJob->setSourceSize64( (*it).size );
- #endif
             newjob = moveJob;
             kdDebug(7007) << "KBearCopyJob::copyNextFile : Moving " << (*it).uSource.prettyURL() << " to " << (*it).uDest.prettyURL() << endl;
             emit moving( this, (*it).uSource, (*it).uDest );
