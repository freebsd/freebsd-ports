--- src/xmms-sid.cc.orig	Thu Aug 26 15:18:41 2004
+++ src/xmms-sid.cc	Thu Aug 26 15:22:22 2004
@@ -196,7 +196,7 @@
 	int fxlen, tn;
 	struct sidTuneInfo sidInf;
 	char *name;
-	enum AFormat fmt = (xs_emuConf.bitsPerSample == 16) ? FMT_S16_NE : FMT_U8;
+	AFormat fmt = (xs_emuConf.bitsPerSample == 16) ? FMT_S16_NE : FMT_U8;
 	gint chn = xs_emuConf.channels;
 
 	tune->getInfo(sidInf);
