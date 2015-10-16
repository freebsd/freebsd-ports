--- src/appmain.h.orig	2013-10-03 09:22:51 UTC
+++ src/appmain.h
@@ -49,7 +49,7 @@ public:
   long onIpcExec(FXObject*o,FXSelector sel,void*p);
   AppClass(const FXString& name, const FXString& title);
   void exit(FXint code);
-  virtual void init(int& argc,char** argv,bool connect=TRUE);
+  virtual void init(int& argc,char** argv,bool connect=true);
   FXString &Commands() { return commands; }
   const FXString &ConfigDir() { return configdir; }
   const FXString &SessionFile() { return sessionfile; }
