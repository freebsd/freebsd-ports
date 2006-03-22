--- totool.cpp.orig	Thu Feb  9 02:21:37 2006
+++ totool.cpp	Fri Mar 17 00:06:08 2006
@@ -442,6 +442,15 @@
         conf = QString::fromLatin1(getenv("HOME"));
     }
     conf.append(QString::fromLatin1(CONFIG_FILE));
+
+# ifdef __FreeBSD__
+// Create the $HOME/.torarc if not exists
+    QString configfile = toExpandFile(conf);
+    QFile cffile(configfile);
+    cffile.open(IO_ReadWrite);
+    cffile.close();
+# endif
+
     try
     {
         loadMap(conf, *Configuration);
