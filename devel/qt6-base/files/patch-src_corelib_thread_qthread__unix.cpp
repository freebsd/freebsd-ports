Support setting thread names via QObject::setObjectName().

PR: 290676

--- src/corelib/thread/qthread_unix.cpp.orig	2025-09-22 07:03:29 UTC
+++ src/corelib/thread/qthread_unix.cpp
@@ -344,14 +344,14 @@ QAbstractEventDispatcher *QThreadPrivate::createEventD
 
 #if QT_CONFIG(thread)
 
-#if (defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_QNX))
+#if (defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_QNX) || defined(Q_OS_FREEBSD))
 static void setCurrentThreadName(const char *name)
 {
 #  if defined(Q_OS_LINUX) && !defined(QT_LINUXBASE)
     prctl(PR_SET_NAME, (unsigned long)name, 0, 0, 0);
 #  elif defined(Q_OS_DARWIN)
     pthread_setname_np(name);
-#  elif defined(Q_OS_QNX)
+#  elif (defined(Q_OS_QNX) || defined(Q_OS_FREEBSD))
     pthread_setname_np(pthread_self(), name);
 #  endif
 }
@@ -415,7 +415,7 @@ void *QThreadPrivate::start(void *arg)
         data->ensureEventDispatcher();
         data->eventDispatcher.loadRelaxed()->startingUp();
 
-#if (defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_QNX))
+#if (defined(Q_OS_LINUX) || defined(Q_OS_DARWIN) || defined(Q_OS_QNX) || defined(Q_OS_FREEBSD))
         {
             // Sets the name of the current thread. We can only do this
             // when the thread is starting, as we don't have a cross
