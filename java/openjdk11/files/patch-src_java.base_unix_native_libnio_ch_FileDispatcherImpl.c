--- src/java.base/unix/native/libnio/ch/FileDispatcherImpl.c
+++ src/java.base/unix/native/libnio/ch/FileDispatcherImpl.c
@@ -291,7 +291,7 @@ Java_sun_nio_ch_FileDispatcherImpl_release0(JNIEnv *env, jobject this,
 static void closeFileDescriptor(JNIEnv *env, int fd) {
     if (fd != -1) {
         int result = close(fd);
-        if (result < 0)
+        if (result < 0 && errno != ECONNRESET)
             JNU_ThrowIOExceptionWithLastError(env, "Close failed");
     }
 }
