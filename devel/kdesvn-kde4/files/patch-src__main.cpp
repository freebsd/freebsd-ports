--- src/main.cpp.old	2013-07-07 17:37:05.617114521 +0200
+++ src/main.cpp	2013-07-07 17:37:20.322929644 +0200
@@ -40,7 +40,6 @@
                      KAboutData::License_GPL,ki18n("(C) 2005-2009 Rajko Albrecht"));
     about.addAuthor( ki18n("Rajko Albrecht"),ki18n("Developer"),QByteArray("ral@alwins-world.de"),QByteArray());
     about.setHomepage("http://kdesvn.alwins-world.de/");
-    about.setBugAddress("kdesvn-bugs@alwins-world.de");
 
     KCmdLineArgs::init(argc, argv, &about);
     KCmdLineOptions options;
