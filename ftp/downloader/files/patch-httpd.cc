--- main/httpd.cc.orig	Thu Mar 28 10:34:34 2002
+++ main/httpd.cc	Sun Jun 16 08:37:50 2002
@@ -179,7 +179,7 @@
 	};
 };
 
-int tHttpDownload::init(tAddr *hostinfo,tCfg *cfg,tSocket *s=NULL) {
+int tHttpDownload::init(tAddr *hostinfo,tCfg *cfg,tSocket *s) {
 	Persistent=0;
 	HTTP=new tHttpClient(cfg);
 	RetrNum=0;
