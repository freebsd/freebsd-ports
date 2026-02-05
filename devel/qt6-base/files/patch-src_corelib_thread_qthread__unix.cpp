Support setting thread names via QObject::setObjectName().

PR: 290676

--- src/corelib/thread/qthread_unix.cpp.orig	2026-01-13 10:18:17 UTC
+++ src/corelib/thread/qthread_unix.cpp
@@ -352,7 +352,7 @@ static void setCurrentThreadName(QThread *thr, String 
         prctl(PR_SET_NAME, (unsigned long)name, 0, 0, 0);
 #  elif defined(Q_OS_DARWIN)
         pthread_setname_np(name);
-#  elif defined(Q_OS_QNX)
+#  elif (defined(Q_OS_QNX) || defined(Q_OS_FREEBSD))
         pthread_setname_np(pthread_self(), name);
 #  else
         Q_UNUSED(name)
