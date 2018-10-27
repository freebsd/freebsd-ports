--- src/anthyconv.h.orig	2003-01-27 13:20:32 UTC
+++ src/anthyconv.h
@@ -13,7 +13,7 @@ class AnthyConv : public KKConv{
 public:
     virtual ~AnthyConv();
     KKContext *createContext(XimIC *);
-    char **getIcon();
+    const char **getIcon();
     void onPushIcon();
     virtual char *getModeName(int );
 private:
