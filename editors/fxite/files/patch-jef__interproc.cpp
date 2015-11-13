--- jef/interproc.cpp.orig	2013-10-03 09:22:51 UTC
+++ jef/interproc.cpp
@@ -323,6 +323,18 @@ static int SocketFailure(const char*func
 }
 
 
+#if (FOX_MINOR>6)
+# if (FOX_MAJOR>1) || (FOX_MINOR>7) || (FOX_LEVEL>49)
+# define FOX_1_7_50_OR_NEWER
+# endif
+#endif
+
+#ifdef FOX_1_7_50_OR_NEWER
+# define LookupInHash(d,k) ((d)->at(k))
+#else
+# define LookupInHash(d,k) ((d)->find(k))
+#endif
+
 
 long InterProc::onSocketRead(FXObject*o,FXSelector sel,void*p)
 {
@@ -344,7 +356,7 @@ long InterProc::onSocketRead(FXObject*o,
       ssize_t len=0;
       char buf[bufsize];
       int read_fd=(FXival)p;
-      FXString*s=(FXString*)connlist->find(p);
+      FXString*s=(FXString*)LookupInHash(connlist,p);
       do {
         len=read(read_fd,buf,bufsize);
         if (len>0) { s->append(buf, len); }
