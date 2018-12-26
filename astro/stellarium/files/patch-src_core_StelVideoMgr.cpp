--- src/core/StelVideoMgr.cpp.orig	2018-12-22 13:39:47 UTC
+++ src/core/StelVideoMgr.cpp
@@ -967,15 +967,15 @@ void StelVideoMgr::setVideoAlpha(const QString&, float
 void StelVideoMgr::resizeVideo(const QString&, float, float) {;}
 void StelVideoMgr::showVideo(const QString&, bool) {;}
 // New functions for 0.15
-qint64 StelVideoMgr::getVideoDuration(const QString&){return -1;}
-qint64 StelVideoMgr::getVideoPosition(const QString&){return -1;}
-QSize StelVideoMgr::getVideoResolution(const QString&){return QSize(0,0);}
-int StelVideoMgr::getVideoWidth(const QString&){return -1;}
-int StelVideoMgr::getVideoHeight(const QString&){return -1;}
+qint64 StelVideoMgr::getVideoDuration(const QString&)const{return -1;}
+qint64 StelVideoMgr::getVideoPosition(const QString&)const{return -1;}
+QSize StelVideoMgr::getVideoResolution(const QString&)const{return QSize(0,0);}
+int StelVideoMgr::getVideoWidth(const QString&)const{return -1;}
+int StelVideoMgr::getVideoHeight(const QString&)const{return -1;}
 void StelVideoMgr::muteVideo(const QString&, bool){;}
 void StelVideoMgr::setVideoVolume(const QString&, int){;}
-int StelVideoMgr::getVideoVolume(const QString&){return -1;}
-bool StelVideoMgr::isVideoPlaying(const QString& id)
+int StelVideoMgr::getVideoVolume(const QString&)const{return -1;}
+bool StelVideoMgr::isVideoPlaying(const QString& id) const
 {
 	Q_UNUSED(id)
 	return false;
