--- ContentDownloader/SheepDownloader.cpp.orig	2020-10-02 21:49:58 UTC
+++ ContentDownloader/SheepDownloader.cpp
@@ -41,7 +42,10 @@
 #include <sys/param.h>
 #include <sys/mount.h>
 #endif
-#ifdef LINUX_GNU
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/mount.h>
+#elif defined(LINUX_GNU)
 #include <sys/statfs.h>
 #include <limits.h>
 #define MAX_PATH PATH_MAX
@@ -780,7 +784,7 @@ void	SheepDownloader::findSheepToDownload()
 			//	Make sure we are really deeply settled asleep, avoids lots of timed out frames.
 			g_Log->Info( "Chilling for %d seconds before trying to download sheeps...", ContentDownloader::INIT_DELAY );
 			
-			thread::sleep( get_system_time() + posix_time::seconds(ContentDownloader::INIT_DELAY) );
+			boost::thread::sleep( get_system_time() + posix_time::seconds(ContentDownloader::INIT_DELAY) );
 		}
 #endif
 
@@ -793,7 +797,7 @@ void	SheepDownloader::findSheepToDownload()
 		while( 1 )
 		{
 
-			this_thread::interruption_point();
+			boost::this_thread::interruption_point();
 			bool incorrect_folder = false;
 #ifdef WIN32
 			ULARGE_INTEGER winlpFreeBytesAvailable, winlpTotalNumberOfBytes, winlpRealBytesAvailable;
@@ -820,14 +824,14 @@ void	SheepDownloader::findSheepToDownload()
 					const char *err = "Content folder is not working.  Downloading disabled.\n";
 					Shepherd::addMessageText( err, strlen(err), 180 ); //3 minutes
 
-					thread::sleep( get_system_time() + posix_time::seconds(TIMEOUT) );
+					boost::thread::sleep( get_system_time() + posix_time::seconds(TIMEOUT) );
 				}
 				else
 				{
 					const char *err = "Low disk space.  Downloading disabled.\n";
 					Shepherd::addMessageText( err, strlen(err), 180 ); //3 minutes
 
-					thread::sleep( get_system_time() + posix_time::seconds(TIMEOUT) );
+					boost::thread::sleep( get_system_time() + posix_time::seconds(TIMEOUT) );
 				
 					boost::mutex::scoped_lock lockthis( s_DownloaderMutex );
 
@@ -938,7 +942,7 @@ void	SheepDownloader::findSheepToDownload()
 								best_anim_old_url = fServerFlock[ static_cast<size_t>(best_anim_old) ]->URL();
 							}
 						}
-						this_thread::interruption_point();
+						boost::this_thread::interruption_point();
 					} while (best_anim != -1);
 
 					if (best_anim_old == -1)
@@ -976,7 +980,7 @@ void	SheepDownloader::findSheepToDownload()
 					badSheepSleepDuration = 10;
 				}
 
-				thread::sleep( get_system_time() + posix_time::seconds(failureSleepDuration) );
+				boost::thread::sleep( get_system_time() + posix_time::seconds(failureSleepDuration) );
 				
 				//failureSleepDuration = TIMEOUT;
 
