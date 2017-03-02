repo-config was aliased to config as of git 1.7 (2010)
and was removed, it seems, in 1.8.5 (2012). None of those
git versions are still supported upstream; switch to git config.

--- src/git.cpp.orig	2009-03-12 17:14:31 UTC
+++ src/git.cpp
@@ -425,7 +425,7 @@ void Git::setTextCodec(QTextCodec* tc) {
 	if (name == "Big5-HKSCS")
 		name = "Big5";
 
-	run("git repo-config i18n.commitencoding " + name);
+	run("git config i18n.commitencoding " + name);
 }
 
 QTextCodec* Git::getTextCodec(bool* isGitArchive) {
@@ -435,7 +435,7 @@ QTextCodec* Git::getTextCodec(bool* isGi
 		return NULL;
 
 	QString runOutput;
-	if (!run("git repo-config --get i18n.commitencoding", &runOutput))
+	if (!run("git config --get i18n.commitencoding", &runOutput))
 		return NULL;
 
 	if (runOutput.isEmpty()) // git docs says default is utf-8
