--- Lphoto/lphoto.py.orig	Sun Nov  7 13:31:59 2004
+++ Lphoto/lphoto.py	Sun Nov  7 13:32:12 2004
@@ -635,7 +635,8 @@
 	KCmdLineArgs.init(sys.argv,about)
 	#KUniqueApplication.addCmdLineOptions()
 	#app = KApplication(sys.argv, "Lphoto")
-	app = KUniqueApplication()
+	#app = KUniqueApplication()
+	app = KApplication()
 	LWaitCursor.setApp(app)
 	mw = LMainPhoto(app)
 	mw.setIcon(QPixmap(paths.art("icon.png")))
