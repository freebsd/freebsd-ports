--- src/mpdstatus.h.orig	Wed Dec  6 18:23:15 2006
+++ src/mpdstatus.h		Fri Jun  1 23:09:14 2007
@@ -33,6 +33,7 @@
 	MPDStatus(const MPDStatus &);
 	~MPDStatus();
 	int volume() const;
+	void setVolume(int vol) const;
 	int repeat() const;
 	int random() const;
 	int playlistLength() const;
