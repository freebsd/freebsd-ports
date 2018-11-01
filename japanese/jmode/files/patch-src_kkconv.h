--- src/kkconv.h.orig	2018-02-10 10:12:06 UTC
+++ src/kkconv.h
@@ -82,7 +82,7 @@ protected:
 class XimIC;
 class KKConv {
 public:
-    virtual char **getIcon()=0;
+    virtual const char **getIcon()=0;
     virtual void onPushIcon()=0;
     virtual KKContext *createContext(XimIC *)=0;
     virtual char *getModeName(int )=0;
@@ -105,7 +105,7 @@ struct Candidates {
 
 bool init_conv();
 KKContext *createKKContext(XimIC *);
-char **getKKIcon();
+const char **getKKIcon();
 void onPushIcon();
 
 void register_kkconv(KKConv *);
