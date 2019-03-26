--- src/java.base/bsd/native/libjava/ProcessHandleImpl_bsd.c
+++ src/java.base/bsd/native/libjava/ProcessHandleImpl_bsd.c
@@ -41,7 +41,8 @@
 #include <sys/sysctl.h>
 
 #ifdef __FreeBSD__
-#include <sys/user.h> // For kinfo_proc
+#include <sys/param.h> // For MAXPATHLEN
+#include <sys/user.h>  // For kinfo_proc
 #endif
 
 #if defined(__OpenBSD__)
@@ -109,8 +110,14 @@ jint os_getChildren(JNIEnv *env, jlong jpid, jlongArray jarray,
     }
 
     // Get buffer size needed to read all processes
+#if defined(__OpenBSD__)
+    u_int namelen = 6;
+    int mib[6] = {CTL_KERN, KERN_PROC, KERN_PROC_ALL, 0, sizeof(struct kinfo_proc), 0};
+#else
+    u_int namelen = 4;
     int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_ALL, 0};
-    if (sysctl(mib, 4, NULL, &bufSize, NULL, 0) < 0) {
+#endif
+    if (sysctl(mib, namelen, NULL, &bufSize, NULL, 0) < 0) {
         JNU_ThrowByNameWithLastError(env,
             "java/lang/RuntimeException", "sysctl failed");
         return -1;
@@ -123,8 +130,12 @@ jint os_getChildren(JNIEnv *env, jlong jpid, jlongArray jarray,
         return -1;
     }
 
+#if defined(__OpenBSD__)
+    mib[5] = bufSize / sizeof(struct kinfo_proc);
+#endif
+
     // Read process info for all processes
-    if (sysctl(mib, 4, buffer, &bufSize, NULL, 0) < 0) {
+    if (sysctl(mib, namelen, buffer, &bufSize, NULL, 0) < 0) {
         JNU_ThrowByNameWithLastError(env,
             "java/lang/RuntimeException", "sysctl failed");
         free(buffer);
@@ -204,9 +215,15 @@ pid_t os_getParentPidAndTimings(JNIEnv *env, pid_t jpid,
     size_t bufSize = sizeof kp;
 
     // Read the process info for the specific pid
+#if defined(__OpenBSD__)
+    u_int namelen = 6;
+    int mib[6] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, pid, bufSize, 1};
+#else
+    u_int namelen = 4;
     int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, pid};
+#endif
 
-    if (sysctl(mib, 4, &kp, &bufSize, NULL, 0) == -1) {
+    if (sysctl(mib, namelen, &kp, &bufSize, NULL, 0) == -1) {
         /*
          * Check errno and throw an exception only if appropriate.
          *
@@ -232,13 +249,13 @@ pid_t os_getParentPidAndTimings(JNIEnv *env, pid_t jpid,
         ppid = kp.KI_PPID;
     }
 
-    // Get cputime if for current process
-    if (pid == getpid()) {
 #ifdef __OpenBSD__
-        jlong microsecs = kp.p_uutime_sec * 1000 * 1000 + kp.p_uutime_usec +
-            kp.p_ustime_sec * 1000 * 1000 + kp.p_ustime_usec;
-        *totalTime = microsecs * 1000;
+    jlong microsecs = kp.p_uutime_sec * 1000 * 1000 + kp.p_uutime_usec +
+        kp.p_ustime_sec * 1000 * 1000 + kp.p_ustime_usec;
+    *totalTime = microsecs * 1000;
 #else
+    // Get cputime if for current process
+    if (pid == getpid()) {
         struct rusage usage;
         if (getrusage(RUSAGE_SELF, &usage) == 0) {
           jlong microsecs =
@@ -246,8 +263,8 @@ pid_t os_getParentPidAndTimings(JNIEnv *env, pid_t jpid,
               usage.ru_stime.tv_sec * 1000 * 1000 + usage.ru_stime.tv_usec;
           *totalTime = microsecs * 1000;
         }
-#endif
     }
+#endif
 
     return ppid;
 }
@@ -260,9 +277,15 @@ static uid_t getUID(pid_t pid) {
     size_t bufSize = sizeof kp;
 
     // Read the process info for the specific pid
+#if defined(__OpenBSD__)
+    u_int namelen = 6;
+    int mib[6] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, pid, bufSize, 1};
+#else
+    u_int namelen = 4;
     int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, pid};
+#endif
 
-    if (sysctl(mib, 4, &kp, &bufSize, NULL, 0) == 0) {
+    if (sysctl(mib, namelen, &kp, &bufSize, NULL, 0) == 0) {
         if (bufSize > 0 && kp.KI_PID == pid) {
             return kp.KI_UID;
         }
@@ -275,22 +298,121 @@ static uid_t getUID(pid_t pid) {
  * into the Info object.
  */
 void os_getCmdlineAndUserInfo(JNIEnv *env, jobject jinfo, pid_t pid) {
-    int mib[4], maxargs, nargs, i;
+    int mib[4], nargs, i;
     size_t size;
-    char *args, *cp, *sp, *np;
+    char *args;
 
     // Get the UID first. This is done here because it is cheap to do it here
     // on other platforms like Linux/Solaris/AIX where the uid comes from the
     // same source like the command line info.
     unix_getUserInfo(env, jinfo, getUID(pid));
 
+#ifdef __OpenBSD__
+    // Get the buffer size needed
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC_ARGS;
+    mib[2] = pid;
+    mib[3] = KERN_PROC_ARGV;
+
+    if (sysctl(mib, 4, NULL, &size, NULL, 0) == -1) {
+        JNU_ThrowByNameWithLastError(env,
+            "java/lang/RuntimeException", "sysctl failed");
+        return;
+    }
+
+    // Allocate space for args and get the arguments
+    args = (char *)malloc(size);
+    if (args == NULL) {
+        JNU_ThrowOutOfMemoryError(env, "malloc failed");
+        return;
+    }
+
+    do {            // a block to break out of on error
+        char **argv;
+        jstring cmdexe = NULL;
+        jclass clazzString;
+        jobject argsArray;
+
+        if (sysctl(mib, 4, args, &size, NULL, 0) == -1) {
+            if (errno != EINVAL) {
+                JNU_ThrowByNameWithLastError(env,
+                    "java/lang/RuntimeException", "sysctl failed");
+            }
+            break;
+        }
+
+        // count the number of argv elements
+        argv = (char **)args;
+        nargs = 0;
+        while (*argv++)
+            nargs++;
+
+        if (nargs < 1)
+            break;
+
+        // reset argv and store command executable path
+        argv = (char **)args;
+        if ((cmdexe = JNU_NewStringPlatform(env, *argv++)) == NULL)
+            break;
+        (*env)->SetObjectField(env, jinfo, ProcessHandleImpl_Info_commandID, cmdexe);
+        if ((*env)->ExceptionCheck(env))
+            break;
+        nargs--;
+
+        // process remaining arguments
+        // Create a String array for nargs elements
+        if ((clazzString = JNU_ClassString(env)) == NULL)
+            break;
+        if ((argsArray = (*env)->NewObjectArray(env, nargs, clazzString, NULL)) == NULL)
+            break;
+
+        for (i = 0; i < nargs; i++) {
+            jstring str;
+            if ((str = JNU_NewStringPlatform(env, argv[i])) == NULL)
+                break;
+
+            (*env)->SetObjectArrayElement(env, argsArray, i, str);
+            if ((*env)->ExceptionCheck(env))
+                break;
+        }
+        if (i == nargs) // no errors in for loop?
+           (*env)->SetObjectField(env, jinfo, ProcessHandleImpl_Info_argumentsID, argsArray);
+    } while (0);
+    // Free the arg buffer
+    free(args);
+#else
+    int maxargs;
+    char cmd[MAXPATHLEN];
+    jstring cmdexe = NULL;
+
+    // Get the resolved name of the executable
+    size = sizeof(cmd);
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_PATHNAME;
+    mib[3] = pid;
+    if (sysctl(mib, 4, cmd, &size, NULL, 0) == -1) {
+        if (errno != EINVAL && errno != ESRCH && errno != EPERM) {
+            JNU_ThrowByNameWithLastError(env,
+                "java/lang/RuntimeException", "sysctl failed");
+        }
+        return;
+    }
+    // Make sure it is null terminated
+    cmd[MAXPATHLEN - 1] = '\0';
+
+    // Store the command executable
+    if ((cmdexe = JNU_NewStringPlatform(env, cmd)) == NULL) {
+        return;
+    }
+
     // Get the maximum size of the arguments
     mib[0] = CTL_KERN;
     mib[1] = KERN_ARGMAX;
     size = sizeof(maxargs);
     if (sysctl(mib, 2, &maxargs, &size, NULL, 0) == -1) {
-            JNU_ThrowByNameWithLastError(env,
-                "java/lang/RuntimeException", "sysctl failed");
+        JNU_ThrowByNameWithLastError(env,
+            "java/lang/RuntimeException", "sysctl failed");
         return;
     }
 
@@ -301,51 +423,44 @@ void os_getCmdlineAndUserInfo(JNIEnv *env, jobject jinfo, pid_t pid) {
         return;
     }
 
-    do {            // a block to break out of on error
-        char *argsEnd;
-        jstring cmdexe = NULL;
-        unsigned namelen;
+    // A block to break out of on error
+    do {
+        char *cp, *argsEnd = NULL;
 
         mib[0] = CTL_KERN;
-#if defined(__OpenBSD__)
-        mib[1] = KERN_PROC_ARGS;
-        mib[2] = pid;
-        namelen = 3;
-#elif defined(__FreeBSD__)
-        mib[0] = CTL_KERN;
         mib[1] = KERN_PROC;
         mib[2] = KERN_PROC_ARGS;
         mib[3] = pid;
-        namelen = 4;
-#endif
         size = (size_t) maxargs;
-        if (sysctl(mib, namelen, args, &size, NULL, 0) == -1) {
-            if (errno != EINVAL) {
+        if (sysctl(mib, 4, args, &size, NULL, 0) == -1) {
+            if (errno != EINVAL && errno != ESRCH && errno != EPERM) {
                 JNU_ThrowByNameWithLastError(env,
                     "java/lang/RuntimeException", "sysctl failed");
             }
             break;
         }
-        memcpy(&nargs, args, sizeof(nargs));
 
-        cp = &args[sizeof(nargs)];      // Strings start after nargs
-        argsEnd = &args[size];
+        // At this point args should hold a flattened argument string with
+        // arguments delimited by NUL and size should hold the overall length
+        // of the string
 
-        // Store the command executable path
-        if ((cmdexe = JNU_NewStringPlatform(env, cp)) == NULL) {
-            break;
-        }
+        // Make sure the string is NUL terminated
+        args[size] = '\0';
 
-        // Skip trailing nulls after the executable path
-        for (cp = cp + strnlen(cp, argsEnd - cp); cp < argsEnd; cp++) {
-            if (*cp != '\0') {
-                break;
-            }
+        // Count the number of arguments
+        nargs = 0;
+        argsEnd = &args[size];
+        for (cp = args; *cp != '\0' && (cp < argsEnd); nargs++) {
+            cp += strnlen(cp, (argsEnd - cp)) + 1;
         }
 
-        unix_fillArgArray(env, jinfo, nargs, cp, argsEnd, cmdexe, NULL);
+        // Copy over all the args
+        cp = args;
+        unix_fillArgArray(env, jinfo, nargs, cp, argsEnd, cmdexe, args);
     } while (0);
+
     // Free the arg buffer
     free(args);
+#endif
 }
 
