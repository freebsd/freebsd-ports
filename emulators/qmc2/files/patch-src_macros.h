--- src/macros.h.orig	2023-11-25 04:55:52 UTC
+++ src/macros.h
@@ -628,13 +628,13 @@
 #define QMC2_VIEWS_PREFIX			QString("Views/")
 
 // Mac OS X uses "~/Library/Application Support/app" rather than "~/.app"
-#define QMC2_SYSCONF_PATH			(QString(XSTR(SYSCONFDIR)).replace(QChar(':'), QLatin1String(" ")) + "/qmc2")
+#define QMC2_SYSCONF_PATH			(QString(XSTR(SYSCONFDIR)).replace(QChar(':'), QLatin1String(" ")))
 #if defined(QMC2_OS_MAC)
 #define QMC2_DOT_PATH				(QDir::homePath() + "/Library/Application Support/qmc2")
 #define QMC2_DEFAULT_DATA_PATH			(QDir::homePath() + "/Library/Application Support/qmc2")
 #else
 #define QMC2_DOT_PATH				(QDir::homePath() + "/.qmc2")
-#define QMC2_DEFAULT_DATA_PATH			QString("data")
+#define QMC2_DEFAULT_DATA_PATH			QString(XSTR(DATADIR))
 #endif
 
 // this allows for changing the configuration path dynamically by adding '-config_path <config_path>' on the command line
