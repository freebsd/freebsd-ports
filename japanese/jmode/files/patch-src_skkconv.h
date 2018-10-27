--- src/skkconv.h.orig	2002-06-15 14:10:40 UTC
+++ src/skkconv.h
@@ -35,7 +35,7 @@ class SKKConv : public KKConv{
 public:
     virtual ~SKKConv();
     //
-    char **getIcon();
+    const char **getIcon();
     void onPushIcon();
     virtual char *getModeName(int );
     //
