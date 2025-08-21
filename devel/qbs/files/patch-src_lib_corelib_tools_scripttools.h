Fix build on i386.

In file included from /wrkdirs/usr/ports/devel/qbs/work/qbs-src-3.0.1/src/lib/corelib/api/internaljobs.cpp:52:
In file included from /wrkdirs/usr/ports/devel/qbs/work/qbs-src-3.0.1/src/lib/corelib/language/scriptengine.h:52:
/wrkdirs/usr/ports/devel/qbs/work/qbs-src-3.0.1/src/lib/corelib/tools/scripttools.h:193:47: error:
member reference base type 'const JSValue' (aka 'const unsigned long long') is not a structure or union
  193 |     operator bool() const { return m_exception.tag != JS_TAG_UNINITIALIZED; }
      |                                    ~~~~~~~~~~~^~~~

--- src/lib/corelib/tools/scripttools.h.orig	2025-06-20 12:42:25 UTC
+++ src/lib/corelib/tools/scripttools.h
@@ -190,7 +190,7 @@ class QBS_AUTOTEST_EXPORT JsException (public)
     JsException(const JsException &) = delete;
     JsException &operator=(const JsException &) = delete;
 
-    operator bool() const { return m_exception.tag != JS_TAG_UNINITIALIZED; }
+    operator bool() const { return !JS_IsUninitialized(m_exception); }
     QString message() const;
     const QStringList stackTrace() const;
     ErrorInfo toErrorInfo() const;
