--- mlib/include/mSysX11.h.orig	2017-02-18 23:19:17 UTC
+++ mlib/include/mSysX11.h
@@ -150,7 +150,7 @@ struct _mAppSystem
 
 #if !defined(MLIB_NO_THREAD)
 	mMutex mutex;
-	int fd_event;
+	int fd_pipe[2];
 #endif
 
 	Atom atoms[MX11_ATOM_NUM];
