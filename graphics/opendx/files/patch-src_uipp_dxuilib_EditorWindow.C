--- src/uipp/dxuilib/EditorWindow.C.orig	2018-07-02 02:13:46 UTC
+++ src/uipp/dxuilib/EditorWindow.C
@@ -5997,7 +5997,7 @@ char msg[128];
     //
     const char *tmpdir = theDXApplication->getTmpDirectory();
     int tmpdirlen = STRLEN(tmpdir);
-    if (!tmpdirlen) return FALSE;
+    if (!tmpdirlen) return (char*) FALSE;
     if (tmpdir[tmpdirlen-1] == '/') {
 	sprintf(netfilename, "%sdx%d.net", tmpdir, getpid());
 	sprintf(cfgfilename, "%sdx%d.cfg", tmpdir, getpid());
