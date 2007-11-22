--- common/AppGlue.h.orig	2007-11-13 22:34:29.000000000 +0100
+++ common/AppGlue.h	2007-11-13 22:34:36.000000000 +0100
@@ -30,8 +30,8 @@
 class CCvsConsole
 {
 public:
-	virtual long cvs_out(char *txt, long len) = 0L;
-	virtual long cvs_err(char *txt, long len) = 0L;
+	virtual long cvs_out(char *txt, long len) = 0;
+	virtual long cvs_err(char *txt, long len) = 0;
 };
 
 #define errInternal -99
