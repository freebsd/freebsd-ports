--- src/corelib/thread/qmutex_unix.cpp.orig	2015-06-13 13:15:35 UTC
+++ src/corelib/thread/qmutex_unix.cpp
@@ -0,0 +1,84 @@
+/***********************************************************************
+*
+* Copyright (c) 2012-2014 Barbara Geller
+* Copyright (c) 2012-2014 Ansel Sermersheim
+* Copyright (c) 2012-2014 Digia Plc and/or its subsidiary(-ies).
+* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
+* All rights reserved.
+*
+* This file is part of CopperSpice.
+*
+* CopperSpice is free software: you can redistribute it and/or 
+* modify it under the terms of the GNU Lesser General Public License
+* version 2.1 as published by the Free Software Foundation.
+*
+* CopperSpice is distributed in the hope that it will be useful,
+* but WITHOUT ANY WARRANTY; without even the implied warranty of
+* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+* Lesser General Public License for more details.
+*
+* You should have received a copy of the GNU Lesser General Public
+* License along with CopperSpice.  If not, see 
+* <http://www.gnu.org/licenses/>.
+*
+***********************************************************************/
+
+#include "qplatformdefs.h"
+#include "qmutex.h"
+
+#if !defined(QT_NO_THREAD)
+
+#include "qmutex_p.h"
+#include <errno.h>
+
+QT_BEGIN_NAMESPACE
+
+QMutexPrivate::QMutexPrivate()
+{
+    wakeup = false;
+}
+
+QMutexPrivate::~QMutexPrivate()
+{
+    /* do nothing */
+}
+
+bool QMutexPrivate::wait(int timeout)
+{
+    int errorCode = 0;
+    while (!wakeup) {
+        if (timeout < 0) {
+            errorCode = pthread_cond_wait(&cond, &mutex);
+        } else {
+            struct timeval tv;
+            gettimeofday(&tv, 0);
+
+            timespec ti;
+            ti.tv_nsec = (tv.tv_usec + (timeout % 1000) * 1000) * 1000;
+            ti.tv_sec  = tv.tv_sec + (timeout / 1000) +
+                         (ti.tv_nsec / 100000000);
+            ti.tv_nsec %= 1000000000;
+            
+            errorCode = pthread_cond_timedwait(&cond, &mutex, &ti);
+        }
+        if (errorCode) {
+            if (errorCode == ETIMEDOUT) {
+                if (wakeup)
+                    errorCode = 0;
+                break;
+            }
+        }
+    }
+    wakeup = false;
+    return errorCode == 0;
+}
+
+void QMutexPrivate::wakeUp()
+{
+    wakeup = true;
+}
+
+
+QT_END_NAMESPACE
+
+#endif //QT_NO_THREAD
