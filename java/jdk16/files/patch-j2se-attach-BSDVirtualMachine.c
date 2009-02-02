$FreeBSD$

--- ../../j2se/src/solaris/native/sun/tools/attach/BSDVirtualMachine.c	11 Oct 2007 02:59:31 -0000	1.2
+++ ../../j2se/src/solaris/native/sun/tools/attach/BSDVirtualMachine.c	2 Feb 2009 00:29:22 -0000
@@ -1 +1,280 @@
-/* empty file for now */
+/*
+ * @(#)BSDVirtualMachine.c    1.8 05/11/21
+ *
+ * Copyright 2006 Sun Microsystems, Inc. All rights reserved.
+ * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
+ */
+
+#include "jni.h"
+#include "jni_util.h"
+
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <errno.h>
+#include <unistd.h>
+#include <signal.h>
+#include <dirent.h>
+#include <ctype.h>
+#include <sys/types.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/stat.h>
+#include <sys/un.h>
+#include <sys/vnode.h>
+#include <sys/user.h>
+#include <sys/sysctl.h>
+#include <fcntl.h>
+
+#include "sun_tools_attach_BSDVirtualMachine.h"
+
+#define RESTARTABLE(_cmd, _result) do { \
+  do { \
+    _result = _cmd; \
+  } while((_result == -1) && (errno == EINTR)); \
+} while(0)
+
+/*
+ * Class:     sun_tools_attach_BSDVirtualMachine
+ * Method:    socket
+ * Signature: ()I
+ */
+JNIEXPORT jint JNICALL Java_sun_tools_attach_BSDVirtualMachine_socket
+  (JNIEnv *env, jclass cls)
+{
+    int fd = socket(PF_UNIX, SOCK_STREAM, 0);
+    if (fd == -1) {
+        JNU_ThrowIOExceptionWithLastError(env, "socket");
+    }
+    return (jint)fd;
+}
+
+/*
+ * Class:     sun_tools_attach_BSDVirtualMachine
+ * Method:    connect
+ * Signature: (ILjava/lang/String;)I
+ */
+JNIEXPORT void JNICALL Java_sun_tools_attach_BSDVirtualMachine_connect
+  (JNIEnv *env, jclass cls, jint fd, jstring path)
+{
+    jboolean isCopy;
+    const char* p = GetStringPlatformChars(env, path, &isCopy);
+    if (p != NULL) {
+        struct sockaddr_un addr;
+        int err = 0;
+        
+        addr.sun_family = AF_UNIX;
+        strcpy(addr.sun_path, p);
+    
+        if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
+            err = errno;
+        }
+    
+        if (isCopy) {
+            JNU_ReleaseStringPlatformChars(env, path, p);
+        }
+    
+        /*
+         * If the connect failed then we throw the appropriate exception
+         * here (can't throw it before releasing the string as can't call
+         * JNI with pending exception)
+         */
+        if (err != 0) {
+            if (err == ENOENT) {
+                JNU_ThrowByName(env, "java/io/FileNotFoundException", NULL);
+            } else {
+                char* msg = strdup(strerror(err));
+            	JNU_ThrowIOException(env, msg);
+    	        if (msg != NULL) {
+       	            free(msg);
+                }
+            }
+        }
+    }
+}
+
+
+/*
+ * Class:     sun_tools_attach_BSDVirtualMachine
+ * Method:    sendQuitTo
+ * Signature: (I)V
+ */
+JNIEXPORT void JNICALL Java_sun_tools_attach_BSDVirtualMachine_sendQuitTo
+  (JNIEnv *env, jclass cls, jint pid)
+{
+    if (kill((pid_t)pid, SIGQUIT)) {
+        JNU_ThrowIOExceptionWithLastError(env, "kill");
+    }
+}
+
+/*
+ * Class:     sun_tools_attach_BSDVirtualMachine
+ * Method:    checkPermissions
+ * Signature: (Ljava/lang/String;)V
+ */
+JNIEXPORT void JNICALL Java_sun_tools_attach_BSDVirtualMachine_checkPermissions
+  (JNIEnv *env, jclass cls, jstring path)
+{
+    jboolean isCopy;
+    const char* p = GetStringPlatformChars(env, path, &isCopy);
+    if (p != NULL) {
+        struct stat sb;
+        uid_t uid, gid;
+        int res;
+
+        /*
+         * Check that the path is owned by the effective uid/gid of this
+         * process. Also check that group/other access is not allowed.
+         */
+        uid = geteuid();
+        gid = getegid();
+
+        res = stat(p, &sb);
+        if (res != 0) {
+            /* save errno */
+            res = errno;
+        }
+
+        /* release p here before we throw an I/O exception */
+        if (isCopy) {
+            JNU_ReleaseStringPlatformChars(env, path, p);
+        }
+
+        if (res == 0) {
+            if ( (sb.st_uid != uid) || (sb.st_gid != gid) ||
+                 ((sb.st_mode & (S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)) != 0) ) {
+                JNU_ThrowIOException(env, "well-known file is not secure");
+            }
+        } else {
+            char* msg = strdup(strerror(res));
+            JNU_ThrowIOException(env, msg);
+            if (msg != NULL) {
+                free(msg);
+            }
+        }
+    }
+}
+
+/*
+ * Class:     sun_tools_attach_BSDVirtualMachine
+ * Method:    close
+ * Signature: (I)V
+ */
+JNIEXPORT void JNICALL Java_sun_tools_attach_BSDVirtualMachine_close
+  (JNIEnv *env, jclass cls, jint fd)
+{
+    int res;
+    RESTARTABLE(close(fd), res);
+}
+
+/*
+ * Class:     sun_tools_attach_BSDVirtualMachine
+ * Method:    read
+ * Signature: (I[BI)I
+ */
+JNIEXPORT jint JNICALL Java_sun_tools_attach_BSDVirtualMachine_read
+  (JNIEnv *env, jclass cls, jint fd, jbyteArray ba, jint off, jint baLen)
+{
+    unsigned char buf[128];
+    size_t len = sizeof(buf);
+    ssize_t n;
+
+    size_t remaining = (size_t)(baLen - off);
+    if (len > remaining) {
+        len = remaining;
+    }
+
+    RESTARTABLE(read(fd, buf+off, len), n);
+    if (n == -1) {
+        JNU_ThrowIOExceptionWithLastError(env, "read");
+    } else {
+        if (n == 0) {
+            n = -1;     // EOF
+        } else {
+            (*env)->SetByteArrayRegion(env, ba, off, (jint)n, (jbyte *)(buf+off));
+        }
+    }
+    return n;
+}
+
+/*
+ * Class:     sun_tools_attach_BSDVirtualMachine
+ * Method:    write
+ * Signature: (I[B)V
+ */
+JNIEXPORT void JNICALL Java_sun_tools_attach_BSDVirtualMachine_write
+  (JNIEnv *env, jclass cls, jint fd, jbyteArray ba, jint off, jint bufLen)
+{
+    size_t remaining = bufLen;
+    do {
+        unsigned char buf[128];
+        size_t len = sizeof(buf);
+        int n;
+    
+        if (len > remaining) {
+            len = remaining;
+        }
+        (*env)->GetByteArrayRegion(env, ba, off, len, (jbyte *)buf);
+    
+        RESTARTABLE(write(fd, buf, len), n);
+        if (n > 0) {
+            off += n;
+            remaining -= n;
+        } else {
+            JNU_ThrowIOExceptionWithLastError(env, "write");
+            return;
+        }
+
+    } while (remaining > 0);
+}
+
+/*
+ * Class:     sun_tools_attach_BSDVirtualMachine
+ * Method:    createAttachFile
+ * Signature: (Ljava.lang.String;)V
+ */
+JNIEXPORT void JNICALL Java_sun_tools_attach_BSDVirtualMachine_createAttachFile(JNIEnv *env, jclass cls, jstring path)
+{
+    const char* _path;
+    jboolean isCopy;
+
+    _path = GetStringPlatformChars(env, path, &isCopy);
+    if (_path == NULL) {
+        JNU_ThrowIOException(env, "Must specify a path");
+        return;
+    }
+
+
+    // Consider error handling
+    int fd = -1;
+    RESTARTABLE(open(_path, O_CREAT | O_EXCL, S_IWUSR | S_IRUSR), fd);
+
+
+
+    if (fd == -1) {
+        /* release p here before we throw an I/O exception */
+        if (isCopy) {
+            JNU_ReleaseStringPlatformChars(env, path, _path);
+        }
+        JNU_ThrowIOExceptionWithLastError(env, "open");
+        return;
+    }
+
+    int chown_rc = -1;
+    RESTARTABLE(chown(_path, geteuid(), getegid()), chown_rc);
+
+    /* release p here before we throw an I/O exception */
+    if (isCopy) {
+        JNU_ReleaseStringPlatformChars(env, path, _path);
+    }
+
+    int close_rc = -1;
+    RESTARTABLE(close(fd),close_rc);
+
+    if (chown_rc == -1) {
+       JNU_ThrowIOExceptionWithLastError(env, "chown");
+    }
+    if (close_rc == -1) {
+       JNU_ThrowIOExceptionWithLastError(env, "close");
+    }
+}
