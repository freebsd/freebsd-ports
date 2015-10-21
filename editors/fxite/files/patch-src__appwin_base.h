--- src/appwin_base.h.orig	2013-10-03 09:22:51 UTC
+++ src/appwin_base.h
@@ -114,7 +114,7 @@ public:
   virtual ~TopWindowBase();
   static TopWindowBase* instance();
   virtual void create();
-  virtual FXbool close(FXbool notify=FALSE);
+  virtual FXbool close(FXbool notify=false);
   void ParseCommands(FXString &commands);
   bool Closing();
   bool IsMacroCancelled();
