--- src/osdep/fsdb_host.cpp.orig	2026-04-25 15:03:50 UTC
+++ src/osdep/fsdb_host.cpp
@@ -642,7 +642,13 @@ bool my_utime(const char* name, const struct mytimeval
 		ok = _utime(path_utf8.c_str(), &utb) == 0;
 #else
 		struct timeval times[2];
+#if defined(__FreeBSD__) && defined(__i386__)
+		times[0].tv_sec = static_cast<time_t>(mtv.tv_sec);
+		times[0].tv_usec = static_cast<suseconds_t>(mtv.tv_usec);
+		times[1] = times[0];
+#else
 		times[0] = times[1] = { mtv.tv_sec, mtv.tv_usec };
+#endif
 		ok = utimes(path_utf8.c_str(), times) == 0;
 #endif
 	}
