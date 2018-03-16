--- thirdparty/thekla_atlas/nvcore/StdStream.h.orig	2017-12-29 19:15:48 UTC
+++ thirdparty/thekla_atlas/nvcore/StdStream.h
@@ -160,14 +160,14 @@ namespace nv
             nvDebugCheck(m_fp != NULL);
 #if NV_OS_WIN32
             return (uint)_fwrite_nolock(data, 1, len, m_fp);
-#elif NV_OS_LINUX
-            return (uint)fwrite_unlocked(data, 1, len, m_fp);
-#elif NV_OS_DARWIN
+#elif NV_OS_DARWIN || NV_OS_FREEBSD || NV_OS_OPENBSD
             // @@ No error checking, always returns len.
             for (uint i = 0; i < len; i++) {
                 putc_unlocked(((char *)data)[i], m_fp);
             }
             return len;
+#elif NV_OS_LINUX
+            return (uint)fwrite_unlocked(data, 1, len, m_fp);
 #else
             return (uint)fwrite(data, 1, len, m_fp);
 #endif
@@ -210,9 +210,7 @@ namespace nv
             nvDebugCheck(m_fp != NULL);
 #if NV_OS_WIN32
             return (uint)_fread_nolock(data, 1, len, m_fp);
-#elif NV_OS_LINUX
-            return (uint)fread_unlocked(data, 1, len, m_fp);
-#elif NV_OS_DARWIN
+#elif NV_OS_DARWIN || NV_OS_FREEBSD || NV_OS_OPENBSD
             // This is rather lame. Not sure if it's faster than the locked version.
             for (uint i = 0; i < len; i++) {
                 ((char *)data)[i] = getc_unlocked(m_fp);
@@ -221,6 +219,8 @@ namespace nv
                 }
             }
             return len;
+#elif NV_OS_LINUX
+            return (uint)fread_unlocked(data, 1, len, m_fp);
 #else
             return (uint)fread(data, 1, len, m_fp);
 #endif
