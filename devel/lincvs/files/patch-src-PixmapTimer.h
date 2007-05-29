--- src/PixmapTimer.h.orig	Tue May 29 17:05:42 2007
+++ src/PixmapTimer.h	Tue May 29 17:05:59 2007
@@ -84,7 +84,7 @@
 
 public:
 	CPixmapTimer(QObject * parent = 0, const char * name = 0);
-	CPixmapTimer::~CPixmapTimer();
+	~CPixmapTimer();
 
 signals:
 	void signalTimeout(const QPixmap &);
