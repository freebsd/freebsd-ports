--- ./src/main.cpp.orig	2013-06-23 10:52:34.000000000 +0000
+++ ./src/main.cpp	2014-04-05 20:24:47.184482481 +0000
@@ -241,8 +241,8 @@
     fprintf(ftty, "Interrupt\n");
     if (ftty != stderr)  fprintf(stderr, "*** Interrupt\n");
 
-    static long last_sigint_time = 0;
-    long curtime;
+    static time_t last_sigint_time = 0;
+    time_t curtime;
     time(&curtime);
     bool isInsisted = (curtime - last_sigint_time <= 2); // re-pressed Ctrl-C after less than 2 secs
     if (!isInsisted && qApp != NULL) {
@@ -446,6 +446,30 @@
   KLFBackend::saveOutputToFile(klfoutput, f_output, format);
 }
 
+void dumpDir(const QDir& d, int indent = 0)
+{
+  char sindent[] = "                                                               ";
+  uint nindent = indent*2; // 2 spaces per indentation
+  if (nindent < strlen(sindent))
+    sindent[nindent] = '\0';
+
+  QStringList dchildren = d.entryList(QDir::Dirs);
+
+  int k;
+  for (k = 0; k < dchildren.size(); ++k) {
+    // skip system ":/trolltech"
+    if (indent == 0 && dchildren[k] == "trolltech")
+      continue;
+    qDebug("%s%s/", sindent, qPrintable(dchildren[k]));
+    dumpDir(QDir(d.absoluteFilePath(dchildren[k])), indent+1);
+  }
+
+  QStringList fchildren = d.entryList(QDir::Files);
+  for (k = 0; k < fchildren.size(); ++k) {
+    qDebug("%s%s", sindent, qPrintable(fchildren[k]));
+  }
+}
+
 void main_load_extra_resources()
 {
   KLF_DEBUG_BLOCK(KLF_FUNC_NAME) ;
@@ -518,36 +542,11 @@
   // set the global "can-import" flag
   klf_addons_canimport = klfsettings_can_import;
 
-  void dumpDir(const QDir&, int = 0);
   klfDbg( "dump of :/ :" ) ;
   dumpDir(QDir(":/"));
 }
 
 
-void dumpDir(const QDir& d, int indent = 0)
-{
-  char sindent[] = "                                                               ";
-  uint nindent = indent*2; // 2 spaces per indentation
-  if (nindent < strlen(sindent))
-    sindent[nindent] = '\0';
-
-  QStringList dchildren = d.entryList(QDir::Dirs);
-
-  int k;
-  for (k = 0; k < dchildren.size(); ++k) {
-    // skip system ":/trolltech"
-    if (indent == 0 && dchildren[k] == "trolltech")
-      continue;
-    qDebug("%s%s/", sindent, qPrintable(dchildren[k]));
-    dumpDir(QDir(d.absoluteFilePath(dchildren[k])), indent+1);
-  }
-
-  QStringList fchildren = d.entryList(QDir::Files);
-  for (k = 0; k < fchildren.size(); ++k) {
-    qDebug("%s%s", sindent, qPrintable(fchildren[k]));
-  }
-}
-
 /** \internal */
 class VersionCompareWithPrefixGreaterThan {
   int prefixLen;
