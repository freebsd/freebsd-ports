--- main/hproxy.cci.orig	Thu Apr  4 03:51:31 2002
+++ main/hproxy.cc	Sun Jun 16 08:35:12 2002
@@ -95,7 +95,7 @@
 tProxyDownload::tProxyDownload(tWriterLoger *log):tHttpDownload(log){
 };
 
-int tProxyDownload::init(tAddr *hostinfo,tCfg *cfg,tSocket *s=NULL) {
+int tProxyDownload::init(tAddr *hostinfo,tCfg *cfg,tSocket *s) {
 	DBC_RETVAL_IF_FAIL(hostinfo!=NULL,-1);
 	DBC_RETVAL_IF_FAIL(cfg!=NULL,-1);
 	HTTP=new tHProxyClient(cfg);
